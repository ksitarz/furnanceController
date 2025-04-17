@echo off
setlocal EnableDelayedExpansion

REM === Nagłówek ===
echo.
echo ========================================
echo         UNIT TESTS - STM32
echo ========================================
echo.

REM === Przejście do folderu skryptu ===
cd /d %~dp0

REM === Tworzenie katalogu build (jeśli brak) ===
if not exist build (
    mkdir build
)

cd build

REM === Konfiguracja i kompilacja ===
echo [INFO] Building project...
cmake .. -G "MinGW Makefiles" > build_log.txt 2>&1
mingw32-make >> build_log.txt 2>&1

if not exist test_controller.exe (
    echo [ERROR] Build failed.
    echo Sprawdź build_log.txt
    exit /b 1
)

REM === Uruchamianie testów ===
echo [INFO] Running test_controller.exe...
.\test_controller.exe > test_output.txt 2>&1

type test_output.txt

REM === Sprawdzenie błędów ===
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
