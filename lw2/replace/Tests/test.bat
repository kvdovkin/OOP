@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program replace.exe
	exit /B 1
)

echo Running Tests...

rem  ���� input ���� 1 �� ������������
%Program%  "" "��" "���" "%TMP%\output.txt" > nul && goto err
echo Test 'subject string not provided' successful
set /A successful+=1

rem  ���� input ���� 2 �� ������������
%Program%  "��-��-��" "" "���" "%TMP%\output.txt" > nul && goto err
echo Test 'search string not provided' successful
set /A successful+=1

rem  ���� input ���� 3 �� ������������
%Program%  "��-��-��" "��" "" "%TMP%\output.txt" > nul && goto err
echo Test 'replace string not provided' successful
set /A successful+=1

rem  ���� output �� ������������
%Program% "��-��-��" "��" "���" "" > nul && goto err
echo Test 'output not provided' successful
set /A successful+=1

rem  ��� ���������� �� ������ �����������
%Program% > nul && goto err
echo Test 'without arguments not work' successful
set /A successful+=1

rem #1
%Program% "��-��-��" "��" "���" "%TMP%\output.txt"|| goto err
fc "outputs\output1.txt" "%TMP%\output.txt" || goto err
echo Test 'check #1' successful
set /A successful+=1

rem #2
%Program% "�� ���� ��������, �� ���� ������" "�� ����" "������" "%TMP%\output.txt"|| goto err
fc "outputs\output2.txt" "%TMP%\output.txt" || goto err
echo Test 'empty file #2' successful
set /A successful+=1

rem #3
%Program% "������ ������ � ����" "������" "��������" "%TMP%\output.txt"|| goto err
fc "outputs\output3.txt" "%TMP%\output.txt" || goto err
echo Test 'check #3' successful
set /A successful+=1

REM Tests passed successfully
echo Tests passed: %successful%/8
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1