# Project Context

- Repository: playground_scheidt_bachmann
- Build system: CMake (root CMakeLists.txt auto-adds subdirectories named chapter_*)
- Language: C++ (configured standard: C++26)
- Focus area for this task: chapter_unittests_01_intro
- chapter_unittests_01_intro builds:
  - Main executable from src/main.cpp
  - Test executable chapter_unittests_01_intro_tests from:
    - tst/test_01_simple.cpp
    - tst/test_02_fixture.cpp
    - tst/test_03_parametrized.cpp
- Testing framework: GoogleTest/GoogleMock via FetchContent
- Test execution: chapter_unittests_01_intro tests are executed after build through a POST_BUILD CTest command
- Scope guardrails for current task:
  - Update only chapter_unittests_01_intro/tst/test_03_parametrized.cpp (and chapter CMake only if inclusion was missing)
  - Keep parameterized-test example educationally simple and compile-correct
