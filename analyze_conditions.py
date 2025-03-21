#!/usr/bin/env python3


import os
import sys
import logging
from src.condition_analyzer.main import main as analyzer_main

if __name__ == '__main__':
    project_root = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, project_root)
    
    analyzer_main() 
