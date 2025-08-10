#!/usr/bin/env python3
"""
Fix all file paths in build_commands.json based on actual ArduPilot structure
"""
import json
import os

def fix_build_commands():
    """Fix all paths in build_commands.json"""
    
    # Read current build commands
    build_cmd_path = "src/adapter/ardupilot/build_commands.json"
    with open(build_cmd_path, 'r') as f:
        commands = json.load(f)
    
    # Known path mappings based on ArduPilot structure
    # Generic files in libraries without vehicle suffix
    generic_files = {
        'RC_Channel.cpp': 'libraries/RC_Channel/RC_Channel.cpp',
        'AP_Arming.cpp': 'libraries/AP_Arming/AP_Arming.cpp',
        'GCS_Mavlink.cpp': 'libraries/GCS_MAVLink/GCS_MAVLink.cpp',
        'AP_Rally.cpp': 'libraries/AP_Rally/AP_Rally.cpp',
    }
    
    # Vehicle-specific files with suffix
    vehicle_suffixes = {
        'ArduCopter': '_Copter',
        'ArduPlane': '_Plane', 
        'Rover': '_Rover',
        'ArduSub': '_Sub',
        'Blimp': '_Blimp',
        'AntennaTracker': '_Tracker'
    }
    
    fixed_count = 0
    
    for cmd in commands:
        if 'file' not in cmd:
            continue
            
        original_file = cmd['file']
        file_name = os.path.basename(original_file)
        
        # Check if it's a generic file that should be in libraries
        for generic_name, library_path in generic_files.items():
            if file_name == generic_name:
                # Check if it's wrongly placed in a vehicle directory
                for vehicle in vehicle_suffixes:
                    if f'/{vehicle}/' in original_file:
                        new_path = original_file.split('/ardupilot/')[0] + '/ardupilot/' + library_path
                        cmd['file'] = new_path
                        print(f"Fixed: {original_file} -> {new_path}")
                        fixed_count += 1
                        break
        
        # Check for vehicle-specific files that need suffix
        for vehicle, suffix in vehicle_suffixes.items():
            if f'/{vehicle}/' in original_file:
                # Check common vehicle-specific files
                if 'RC_Channel.cpp' in file_name and not suffix in file_name:
                    base_name = file_name.replace('.cpp', '')
                    new_name = f"{base_name}{suffix}.cpp"
                    cmd['file'] = original_file.replace(file_name, new_name)
                    print(f"Fixed: {original_file} -> {cmd['file']}")
                    fixed_count += 1
                elif 'AP_Arming.cpp' in file_name and not suffix in file_name:
                    base_name = file_name.replace('.cpp', '')
                    new_name = f"{base_name}{suffix}.cpp"
                    cmd['file'] = original_file.replace(file_name, new_name)
                    print(f"Fixed: {original_file} -> {cmd['file']}")
                    fixed_count += 1
                elif 'GCS_Mavlink' in file_name and not suffix in file_name:
                    # GCS_Mavlink files don't have suffix in vehicle directories
                    pass
    
    # Save fixed commands
    with open(build_cmd_path, 'w') as f:
        json.dump(commands, f, indent=2)
    
    print(f"\nTotal fixes applied: {fixed_count}")
    print(f"Build commands saved to: {build_cmd_path}")

if __name__ == "__main__":
    fix_build_commands()