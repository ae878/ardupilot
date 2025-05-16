import json
from graphviz import Digraph
import networkx as nx
import argparse
import re


class Node:
    def __init__(self, name, id):
        self.name = name
        self.id = id
        self.children = []


def simplify_label(label):
    # Remove backslashes and line continuations
    label = label.replace("\\", "")
    # Remove extra spaces
    label = " ".join(label.split())
    # Truncate if too long
    if len(label) > 50:
        label = label[:47] + "..."
    return label


def get_block_dependencies(block, graph, parent_node_struct: Node, parent_node=None):
    if "child_blocks" in block:
        for child_block in block["child_blocks"]:
            for branch in child_block["branches"]:
                child_name = branch["condition"]
                if child_name:
                    # Create a simple node ID
                    node_id = f"n{hash(child_name) & 0xffffffff}"
                    # Create simple label
                    label = simplify_label(child_name)

                    # Add child node
                    graph.node(node_id, label)
                    child_node = Node(child_name, node_id)
                    parent_node_struct.children.append(child_node)
                    if parent_node:
                        graph.edge(parent_node, node_id)

                    # Recursively process child blocks
                    get_block_dependencies(child_block, graph, child_node, node_id)


def create_macro_dependency_graph(macros, target_macro=None):
    # Create graph
    graph = {}
    if target_macro:
        dot = Digraph(comment=f"Dependency Graph for {target_macro}")
        output_file = f"macro_dependency_{target_macro}"
    else:
        dot = Digraph(comment="Macro Dependency Graph")
        output_file = "macro_dependency_graph"

    # Set graph attributes
    dot.attr(rankdir="TB")
    dot.attr("node", shape="box", style="rounded,filled", fillcolor="lightblue")
    dot.attr("edge", style="solid")

    if target_macro:
        # Single macro mode
        if target_macro not in macros:
            print(f"Macro {target_macro} not found")
            return

        # Add root node
        node_id = f"n{hash(target_macro) & 0xffffffff}"
        dot.node(node_id, target_macro)
        target_node = Node(target_macro, node_id)
        graph[target_macro] = target_node
        # Process each conditional scope
        for conditional_scope in macros[target_macro]["conditional_scopes"]:
            get_block_dependencies(conditional_scope["block_structure"], dot, target_node, node_id)
        # Save graph to file
        dot.render(output_file, view=True)
    else:
        # All macros mode
        # Add anonymous root node
        root_node = "ROOT"
        dot.node(root_node, "ROOT", style="invis")  # invisible root node

        # Process each macro
        for macro_name, macro_data in macros.items():
            # Add macro node
            node_id = f"n{hash(macro_name) & 0xffffffff}"
            dot.node(node_id, macro_name)
            # Connect to root
            dot.edge(root_node, node_id)
            target_node = Node(macro_name, node_id)
            graph[macro_name] = target_node

            # Process each conditional scope
            for conditional_scope in macro_data["conditional_scopes"]:
                get_block_dependencies(conditional_scope["block_structure"], dot, target_node, node_id)

    # Print all nodes and edges
    total_nodes = 0
    total_edges = 0
    print("\nNodes in the graph:")
    for macro_name, node in graph.items():
        total_nodes += 1
        print(f"Node: {node.name} ({node.id})")
        for child in node.children:
            total_edges += 1
            print(f"Edge: {node.name} -> {child.name} ({child.id})")
    print(f"Total nodes: {total_nodes}")
    print(f"Total edges: {total_edges}")

    # Calculate graph metrics using networkx
    G = nx.DiGraph()

    # Add nodes and edges from the dot file
    for line in dot.body:
        line = line.strip()
        if line.startswith('"') and "->" in line:
            # Parse edge
            parts = line.split("->")
            source = parts[0].strip('"')
            target = parts[1].strip('"').strip(";")
            G.add_edge(source, target)
        elif line.startswith('"') and "[" in line:
            # Parse node
            node_name = line.split("[")[0].strip('"')
            G.add_node(node_name)

    print("\nGraph metrics:")
    print(f"Number of nodes: {len(G.nodes)}")
    print(f"Number of edges: {len(G.edges)}")

    # Only calculate metrics if graph is not empty
    if len(G.nodes) > 0:
        undirected_G = G.to_undirected()
        if nx.is_connected(undirected_G):
            print(f"Graph diameter: {nx.diameter(undirected_G)}")
            print(f"Average shortest path length: {nx.average_shortest_path_length(undirected_G)}")
        else:
            print("Graph is not connected")
            print("Number of connected components:", nx.number_connected_components(undirected_G))
    else:
        print("Empty graph - no metrics to calculate")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate macro dependency graph")
    parser.add_argument("--macro", type=str, help="Specific macro to generate graph for")
    args = parser.parse_args()

    with open("../src/adapter/wideband/macros.json", "r") as f:
        macros = json.load(f)

    create_macro_dependency_graph(macros, args.macro)
