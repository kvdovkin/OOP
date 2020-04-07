@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program multmatrix.exe
	exit /B 1
)

echo Running Tests...

rem  Если input файл 1 не предоставлен
%Program% "" "tests\matrixfile2\matrix1.txt" "%TMP%\output.txt" > nul && goto err
echo Test 'input1 not provided' successful
set /A successful+=1

rem  Если input файл 2 не предоставлен
%Program% "tests\matrixfile1\matrix1.txt" "" "%TMP%\output.txt" > nul && goto err
echo Test 'input2 not provided' successful
set /A successful+=1

rem  Если output не предоставлен
%Program% "tests\matrixfile1\matrix1.txt" "tests\matrixfile2\matrix1.txt" "" > nul && goto err
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
%Program% "tests\matrixfile1\matrix1.txt" "tests\matrixfile2\matrix1.txt" "%TMP%\output.txt"|| goto err
fc "tests\outputs\output1.txt" "%TMP%\output.txt" || goto err
echo Test 'multmatrix #1' successful
set /A successful+=1

rem #2
%Program% "tests\matrixfile1\matrix2.txt" "tests\matrixfile2\matrix2.txt" "%TMP%\output.txt"|| goto err
fc "tests\outputs\output2.txt" "%TMP%\output.txt" || goto err
echo Test 'multmatrix #2 to zero matrix' successful
set /A successful+=1

rem #3
%Program% "tests\matrixfile1\matrix3.txt" "tests\matrixfile2\matrix3.txt" "%TMP%\output.txt"|| goto err
fc "tests\outputs\output3.txt" "%TMP%\output.txt" || goto err
echo Test 'multmatrix #3' successful
set /A successful+=1

rem #4
%Program% "tests\matrixfile1\matrix4.txt" "tests\matrixfile2\matrix4.txt" "%TMP%\output.txt"|| goto err
fc "tests\outputs\output4.txt" "%TMP%\output.txt" || goto err
echo Test 'multmatrix #4' successful
set /A successful+=1

rem #5 Умножение на единичную матрицу
%Program% "tests\matrixfile1\matrix5.txt" "tests\matrixfile2\matrix5.txt" "%TMP%\output.txt"|| goto err
fc "tests\outputs\output5.txt" "%TMP%\output.txt" || goto err
echo Test 'multmatrix #5 to one matrix' successful
set /A successful+=1

REM Tests passed successfully
echo Tests passed: %successful%/10
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1