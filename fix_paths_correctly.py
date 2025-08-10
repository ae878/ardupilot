#!/usr/bin/env python3
"""
Correctly fix all file paths in build_commands.json
"""
import json
import os
import re

def fix_build_commands():
    """Fix all paths in build_commands.json"""
    
    # Read current build commands
    build_cmd_path = "src/adapter/ardupilot/build_commands.json"
    
    # Backup original
    with open(build_cmd_path, 'r') as f:
        commands = json.load(f)
    
    with open(build_cmd_path + '.backup', 'w') as f:
        json.dump(commands, f, indent=2)
    
    # Files that should be in libraries (without vehicle suffix)
    library_files = {
        'RC_Channel.cpp': 'libraries/RC_Channel/RC_Channel.cpp',
        'RC_Channel.h': 'libraries/RC_Channel/RC_Channel.h',
        'AP_Arming.cpp': 'libraries/AP_Arming/AP_Arming.cpp',
        'AP_Arming.h': 'libraries/AP_Arming/AP_Arming.h',
        'AP_Rally.cpp': 'libraries/AP_Rally/AP_Rally.cpp',
        'AP_Rally.h': 'libraries/AP_Rally/AP_Rally.h',
    }
    
    # Vehicle-specific files (with suffix)
    vehicle_specific = {
        'ArduCopter': {
            'RC_Channel.cpp': 'RC_Channel_Copter.cpp',
            'RC_Channel.h': 'RC_Channel_Copter.h',
            'AP_Arming.cpp': 'AP_Arming_Copter.cpp',
            'AP_Arming.h': 'AP_Arming_Copter.h',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',  # No suffix
            'GCS_Mavlink.h': 'GCS_Mavlink.h',      # No suffix
        },
        'ArduPlane': {
            'RC_Channel.cpp': 'RC_Channel_Plane.cpp',
            'RC_Channel.h': 'RC_Channel_Plane.h',
            'AP_Arming.cpp': 'AP_Arming_Plane.cpp',
            'AP_Arming.h': 'AP_Arming_Plane.h',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',
            'GCS_Mavlink.h': 'GCS_Mavlink.h',
        },
        'Rover': {
            'RC_Channel.cpp': 'RC_Channel_Rover.cpp',
            'RC_Channel.h': 'RC_Channel_Rover.h',
            'AP_Arming.cpp': 'AP_Arming_Rover.cpp',
            'AP_Arming.h': 'AP_Arming_Rover.h',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',
            'GCS_Mavlink.h': 'GCS_Mavlink.h',
        },
        'ArduSub': {
            'RC_Channel.cpp': 'RC_Channel_Sub.cpp',
            'RC_Channel.h': 'RC_Channel_Sub.h',
            'AP_Arming.cpp': 'AP_Arming_Sub.cpp',
            'AP_Arming.h': 'AP_Arming_Sub.h',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',
            'GCS_Mavlink.h': 'GCS_Mavlink.h',
        },
        'Blimp': {
            'RC_Channel.cpp': 'RC_Channel_Blimp.cpp',
            'AP_Arming.cpp': 'AP_Arming_Blimp.cpp',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',
            'GCS_Mavlink.h': 'GCS_Mavlink.h',
        },
        'AntennaTracker': {
            'RC_Channel.cpp': 'RC_Channel_Tracker.cpp',
            'GCS_Mavlink.cpp': 'GCS_Mavlink.cpp',
        }
    }
    
    fixed_count = 0
    
    for cmd in commands:
        if 'file' not in cmd:
            continue
            
        original_file = cmd['file']
        file_name = os.path.basename(original_file)
        
        # Extract the base path (up to ardupilot/)
        match = re.search(r'(.*?/ardupilot/)', original_file)
        if not match:
            continue
            
        base_path = match.group(1)
        relative_path = original_file[len(base_path):]
        
        # Check which vehicle directory this is in
        vehicle = None
        for v in vehicle_specific.keys():
            if relative_path.startswith(v + '/'):
                vehicle = v
                break
        
        if vehicle:
            # Check if this file should be vehicle-specific
            if file_name in vehicle_specific[vehicle]:
                # Update to vehicle-specific filename
                new_filename = vehicle_specific[vehicle][file_name]
                new_path = base_path + vehicle + '/' + new_filename
                if new_path != original_file:
                    cmd['file'] = new_path
                    print(f"Fixed: {original_file} -> {new_path}")
                    fixed_count += 1
            elif file_name in library_files:
                # This should be in libraries instead
                new_path = base_path + library_files[file_name]
                cmd['file'] = new_path
                print(f"Fixed: {original_file} -> {new_path}")
                fixed_count += 1
    
    # Save fixed commands
    with open(build_cmd_path, 'w') as f:
        json.dump(commands, f, indent=2)
    
    print(f"\nTotal fixes applied: {fixed_count}")
    print(f"Build commands saved to: {build_cmd_path}")
    print(f"Backup saved to: {build_cmd_path}.backup")

if __name__ == "__main__":
    fix_build_commands()