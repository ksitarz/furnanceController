@echo off
setlocal EnableDelayedExpansion

REM === Clean build directory if requested ===
if "%1"=="clean" (
    echo Cleaning build...
    rmdir /s /q build
    exit /b
)

REM === Header ===
echo.
echo ========================================
echo          UNIT TESTS - STM32
echo ========================================
echo.

REM === Create build dir if needed ===
if not exist build (
    mkdir build
)

cd build

REM === Configure and build ===
cmake .. -G "MinGW Makefiles" >nul
mingw32-make >nul 2>&1

if not exist test_controller.exe (
    echo [ERROR] Build failed.
    exit /b 1
)

REM === Run tests and capture output ===
echo Running test_controller.exe...
.\test_controller.exe > test_output.txt 2>&1

REM === Display test results ===
type test_output.txt

REM === Check result ===
findstr /C:"FAIL" test_output.txt >nul
if %ERRORLEVEL%==0 (
    echo.
    echo [FAIL] Some tests failed.
) else (
    echo.
    echo [PASS] All tests passed.
)

echo.
pause
