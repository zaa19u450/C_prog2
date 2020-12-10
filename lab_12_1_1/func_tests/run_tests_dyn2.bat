@echo off
cls
(cd ..)
echo POSITIVES
echo pos_01_test
app_dyn2.exe func_tests\\pos_01_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_01_out.txt) else ( echo Failed!)
pause
echo pos_02_test
app_dyn2.exe func_tests\\pos_02_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_02_out.txt) else ( echo Failed!)
pause
echo pos_03_test
app_dyn2.exe func_tests\\pos_03_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_03_out.txt) else ( echo Failed!)
pause
echo pos_04_test
app_dyn2.exe func_tests\\pos_04_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_04_out.txt) else ( echo Failed!)
pause
echo pos_05_test
app_dyn2.exe func_tests\\pos_05_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_05_out.txt) else ( echo Failed!)
pause

echo pos_06_test
app_dyn2.exe func_tests\\pos_06_in.txt func_tests\\out.txt f
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_06_out.txt) else ( echo Failed!)
pause
echo pos_07_test
app_dyn2.exe func_tests\\pos_07_in.txt func_tests\\out.txt f
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_07_out.txt) else ( echo Failed!)
pause
echo pos_08_test
app_dyn2.exe func_tests\\pos_08_in.txt func_tests\\out.txt f
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_08_out.txt) else ( echo Failed!)
pause
echo pos_09_test
app_dyn2.exe func_tests\\pos_09_in.txt func_tests\\out.txt f
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_09_out.txt) else ( echo Failed!)
pause


echo NEGATIVES
echo neg_01_test
app_dyn2.exe func_tests\\file_in.txt
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause
echo neg_02_test
app_dyn2.exe func_tests\\file_in.txt func_tests\\file_out.txt f toomuch
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause
echo neg_03_test
app_dyn2.exe func_tests\\file_in.txt func_tests\\file_out.txt F
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause
echo neg_04_test
app_dyn2.exe func_tests\\does_not_exist.txt func_tests\\file_out.txt
if errorlevel -2 ( echo PASSED!) else ( echo Failed!)
pause


echo neg_06_test
app_dyn2.exe func_tests\\neg_06_in.txt func_tests\\neg_06_out.txt
if errorlevel -3 ( echo PASSED!) else ( echo Failed!)
pause
echo neg_07_test
app_dyn2.exe func_tests\\neg_07_in.txt func_tests\\neg_07_out.txt f
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause
echo neg_08_test
app_dyn2.exe func_tests\\neg_08_in.txt func_tests\\neg_08_out.txt f
if errorlevel -6 ( echo PASSED!) else ( echo Failed!)
pause
