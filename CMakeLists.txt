cmake_minimum_required(VERSION 3.28)
project(cppCodingTest)

set(CMAKE_CXX_STANDARD 17)

# src 디렉토리 내의 모든 .cpp 파일을 가져옵니다.
file(GLOB SOURCES "src/Seven_week/*.cpp")

# 각 소스 파일마다 별도의 실행 파일을 생성합니다.
foreach (source_file ${SOURCES})
    # 소스 파일의 파일명(확장자 제외)을 가져옵니다.
    get_filename_component(exec_name ${source_file} NAME_WE)
    add_executable(${exec_name} ${source_file}
    )
endforeach ()