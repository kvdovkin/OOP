@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program compare.exe
	exit /B 1
)

echo Running Tests...

rem  Если input файл 1 не предоставлен
%Program% "" "tests\file2\input1.txt" "%TMP%\output.txt" > nul && goto err
echo Test 'input1 not provided' successful
set /A successful+=1

rem  Если input файл 2 не предоставлен
%Program% "tests\file1\input1.txt" "" "%TMP%\output.txt" > nul && goto err
echo Test 'input2 not provided' successful
set /A successful+=1

rem  Если output не предоставлен
%Program% "tests\file1\input1.txt" "tests\file2\input1.txt" "" > nul && goto err
echo Test 'output not provided' successful
set /A successful+=1

rem  Если оба файла не предоставлены
%Program% "" "" "%TMP%\output.txt" > nul && goto err
echo Test 'both input file not provided' successful
set /A successful+=1

rem  Без аргументов не должна выполняться
%Program% > nul && goto err
echo Test 'without arguments not work' successful
set /A successful+=1

rem #1
%Program% "..\tests\file1\input1.txt" "..\tests\file2\input1.txt" "%TMP%\output.txt"|| goto err
fc "..\tests\outputs\output1.txt" "%TMP%\output.txt" || goto err
echo Test 'equal file' successful
set /A successful+=1

rem #2
%Program% "..\tests\file1\input2.txt" "..\tests\file2\input2.txt" "%TMP%\output.txt"|| goto err
fc "..\tests\outputs\output2.txt" "%TMP%\output.txt" || goto err
echo Test 'not equal file' successful
set /A successful+=1

rem #3
%Program% "..\tests\file1\input3.txt" "..\tests\file2\input3.txt" "%TMP%\output.txt"|| goto err
fc "..\tests\outputs\output3.txt" "%TMP%\output.txt" || goto err
echo Test 'empty files' successful
set /A successful+=1

REM Tests passed successfully
echo Tests passed: %successful%/8
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1