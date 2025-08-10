#!/usr/bin/env python3
"""
Final fix for build_commands.json paths
"""
import json
import os

def fix_build_commands():
    # Read build commands
    build_cmd_path = "src/adapter/ardupilot/build_commands.json"
    with open(build_cmd_path, 'r') as f:
        commands = json.load(f)
    
    # Base path for ArduPilot
    ardupilot_base = "/home/ubuntu/lab/ardupilot"
    
    fixed_count = 0
    
    for cmd in commands:
        if 'file' in cmd and cmd['file'].startswith('../../'):
            # Convert relative path to absolute
            rel_path = cmd['file'].replace('../../', '')
            cmd['file'] = os.path.join(ardupilot_base, rel_path)
            fixed_count += 1
        
        if 'directory' in cmd and 'AIRLink' in cmd['directory']:
            # Already looks correct
            pass
    
    # Now fix specific problematic files
    for cmd in commands:
        if 'file' not in cmd:
            continue
            
        file_path = cmd['file']
        file_name = os.path.basename(file_path)
        
        # Fix vehicle-specific files that have wrong names
        replacements = {
            # ArduCopter
            '/ArduCopter/RC_Channel.cpp': '/ArduCopter/RC_Channel_Copter.cpp',
            '/ArduCopter/AP_Arming.cpp': '/ArduCopter/AP_Arming_Copter.cpp',
            # ArduPlane  
            '/ArduPlane/RC_Channel.cpp': '/ArduPlane/RC_Channel_Plane.cpp',
            '/ArduPlane/AP_Arming.cpp': '/ArduPlane/AP_Arming_Plane.cpp',
            # Rover
            '/Rover/RC_Channel.cpp': '/Rover/RC_Channel_Rover.cpp',
            '/Rover/AP_Arming.cpp': '/Rover/AP_Arming_Rover.cpp',
            # ArduSub
            '/ArduSub/RC_Channel.cpp': '/ArduSub/RC_Channel_Sub.cpp',
            '/ArduSub/AP_Arming.cpp': '/ArduSub/AP_Arming_Sub.cpp',
            # Blimp
            '/Blimp/RC_Channel.cpp': '/Blimp/RC_Channel_Blimp.cpp',
            '/Blimp/AP_Arming.cpp': '/Blimp/AP_Arming_Blimp.cpp',
            # AntennaTracker
            '/AntennaTracker/RC_Channel.cpp': '/AntennaTracker/RC_Channel_Tracker.cpp',
        }
        
        for old_path, new_path in replacements.items():
            if file_path.endswith(old_path):
                cmd['file'] = file_path.replace(old_path, new_path)
                print(f"Fixed: {file_path} -> {cmd['file']}")
                fixed_count += 1
                break
    
    # Save
    with open(build_cmd_path, 'w') as f:
        json.dump(commands, f, indent=2)
    
    print(f"\nTotal fixes: {fixed_count}")
    print("Saved to:", build_cmd_path)

if __name__ == "__main__":
    fix_build_commands()