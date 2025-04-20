import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
import json
import time

target_thread_functions = [
    "AP_OAPathPlanner::avoidance_thread",
    "CANSensor::loop",
    "Compass::_update_calibration_trampoline",
    "AP_DDS_Client::main_loop",
    "AP_DroneCAN::loop",
    "AP_ExternalAHRS_InertialLabs::update_thread",
    "AP_ExternalAHRS_MicroStrain5::update_thread",
    "AP_ExternalAHRS_MicroStrain7::update_thread",
    "AP_ExternalAHRS_VectorNav::update_thread",
    "AP_Frsky_Backend::loop",
    "AP_GPS_Backend::logging_start",
    "AP_GyroFFT::update_thread",
    "BinarySemTest::thread1",
    "BinarySemTest::thread2",
    "RCOutput::led_thread",
    "GPIO_Sysfs::_gpio_script_thread",
    "AP_Hott_Telem::loop",
    "AP_InertialSensor_ADIS1647x::loop",
    "AP_IOMCU::thread_main",
    "AP_KDECAN_Driver::loop",
    "AP_Logger::io_thread",
    "AP_Mount_Backend::calculate_poi",
    "AP_MSP::loop",
    "AP_Networking_ChibiOS::thread",
    "AP_Networking_PPP::ppp_loop",
    "AP_Networking::sendfile_check",
    "ThreadWrapper::run",
    "AP_OSD::osd_thread",
    "AP_PiccoloCAN::loop",
    "AP_Scripting::thread",
    "AP_Torqeedo_TQBus::thread_main",
    "AP_SmartAudio::loop",
    "GCS_MAVLINK::ftp_worker",
    "FlightAxis::socket_creator",
]
ardupilot_base = "/home/ubuntu/lab/ardupilot"
build_base = "/home/ubuntu/lab/ardupilot/build/R9Pilot"
thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"


# Set config file path for creating config.h
config1 = ConfigFactory("src/adapter/ardupilot/macros.json")
with open("src/adapter/ardupilot/build_commands.json", "r") as f:
    build_commands = json.load(f)

adapter = ArdupilotAdapter(
    ardupilot_base, build_commands, thread_functions_file_path=thread_functions_file_path, verbose=True
)
# adapter.build()


fuzzer = Fuzzer(ardupilot_base, adapter, config=config1, verbose=True)
# fuzzer.initial_analyze(target_thread_functions)
# with open("fuzzer.json", "w") as f:
#     json.dump(list(fuzzer.related_files_per_function["task_mavobc_entry"]), f)

# 24시간(86400초) 제한 설정
start_program = time.time()
MAX_RUNTIME = 86400  # 24시간을 초단위로 표시
# fuzzer.change_config_with_seed(config2)
while True:
    # 전체 실행 시간 체크
    if time.time() - start_program > MAX_RUNTIME:
        print("24시간이 경과하여 프로그램을 종료합니다.")
        break
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    fuzzer.mutate(target_thread_functions, methods=[])
