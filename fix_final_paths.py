#!/usr/bin/env python3
"""
Fix all file paths based on actual ArduPilot structure
"""
import json
import os

def fix_all_paths():
    # Read build commands
    with open('src/adapter/ardupilot/build_commands.json', 'r') as f:
        commands = json.load(f)
    
    # Actual file mappings based on ArduPilot structure
    file_mappings = {
        # ArduCopter
        '/ArduCopter/RC_Channel.cpp': '/ArduCopter/RC_Channel_Copter.cpp',
        '/ArduCopter/AP_Arming.cpp': '/ArduCopter/AP_Arming_Copter.cpp',
        '/ArduCopter/GCS_Mavlink.cpp': '/ArduCopter/GCS_MAVLink_Copter.cpp',
        '/ArduCopter/GCS_Mavlink.h': '/ArduCopter/GCS_MAVLink_Copter.h',
        
        # ArduPlane
        '/ArduPlane/RC_Channel.cpp': '/ArduPlane/RC_Channel_Plane.cpp',
        '/ArduPlane/AP_Arming.cpp': '/ArduPlane/AP_Arming_Plane.cpp',
        '/ArduPlane/GCS_Mavlink.cpp': '/ArduPlane/GCS_MAVLink_Plane.cpp',
        '/ArduPlane/GCS_Mavlink.h': '/ArduPlane/GCS_MAVLink_Plane.h',
        
        # Rover
        '/Rover/RC_Channel.cpp': '/Rover/RC_Channel_Rover.cpp',
        '/Rover/AP_Arming.cpp': '/Rover/AP_Arming_Rover.cpp',
        '/Rover/GCS_Mavlink.cpp': '/Rover/GCS_MAVLink_Rover.cpp',
        '/Rover/GCS_Mavlink.h': '/Rover/GCS_MAVLink_Rover.h',
        
        # ArduSub
        '/ArduSub/RC_Channel.cpp': '/ArduSub/RC_Channel_Sub.cpp',
        '/ArduSub/AP_Arming.cpp': '/ArduSub/AP_Arming_Sub.cpp',
        '/ArduSub/GCS_Mavlink.cpp': '/ArduSub/GCS_MAVLink_Sub.cpp',
        '/ArduSub/GCS_Mavlink.h': '/ArduSub/GCS_MAVLink_Sub.h',
        
        # Blimp
        '/Blimp/RC_Channel.cpp': '/Blimp/RC_Channel_Blimp.cpp',
        '/Blimp/AP_Arming.cpp': '/Blimp/AP_Arming_Blimp.cpp',
        '/Blimp/GCS_Mavlink.cpp': '/Blimp/GCS_MAVLink_Blimp.cpp',
        '/Blimp/GCS_Mavlink.h': '/Blimp/GCS_MAVLink_Blimp.h',
        
        # AntennaTracker
        '/AntennaTracker/RC_Channel.cpp': '/AntennaTracker/RC_Channel_Tracker.cpp',
        '/AntennaTracker/GCS_Mavlink.cpp': '/AntennaTracker/GCS_MAVLink_Tracker.cpp',
        
        # Files that don't exist (remove from build)
        '/libraries/AP_HAL_Linux/RCInput_Navio2.cpp': None,  # This file doesn't exist
    }
    
    fixed_count = 0
    removed_count = 0
    commands_to_keep = []
    
    for cmd in commands:
        if 'file' not in cmd:
            commands_to_keep.append(cmd)
            continue
        
        file_path = cmd['file']
        should_remove = False
        
        # Check each mapping
        for old_pattern, new_pattern in file_mappings.items():
            if file_path.endswith(old_pattern):
                if new_pattern is None:
                    # File doesn't exist, skip this command
                    should_remove = True
                    removed_count += 1
                    print(f"Removing non-existent file: {file_path}")
                else:
                    # Update the path
                    new_path = file_path.replace(old_pattern, new_pattern)
                    cmd['file'] = new_path
                    fixed_count += 1
                    print(f"Fixed: {file_path} -> {new_path}")
                break
        
        if not should_remove:
            commands_to_keep.append(cmd)
    
    # Save fixed commands
    with open('src/adapter/ardupilot/build_commands.json', 'w') as f:
        json.dump(commands_to_keep, f, indent=2)
    
    print(f"\nTotal fixes: {fixed_count}")
    print(f"Total removed: {removed_count}")
    print(f"Commands remaining: {len(commands_to_keep)}")

if __name__ == "__main__":
    fix_all_paths()