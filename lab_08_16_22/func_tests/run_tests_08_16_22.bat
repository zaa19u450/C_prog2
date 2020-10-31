@echo off
cls
(cd ..)


echo POSITIVES

echo pos_01_test
app.exe a func_tests\\pos_01_in_1.txt func_tests\\pos_01_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_01_out.txt) else ( echo Failed!)
pause

echo pos_02_test
app.exe a func_tests\\pos_02_in_1.txt func_tests\\pos_02_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_02_out.txt) else ( echo Failed!)
pause

echo pos_03_test
app.exe a func_tests\\pos_03_in_1.txt func_tests\\pos_03_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_03_out.txt) else ( echo Failed!)
pause

echo pos_04_test
app.exe m func_tests\\pos_04_in_1.txt func_tests\\pos_04_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_04_out.txt) else ( echo Failed!)
pause


echo pos_05_test
app.exe m func_tests\\pos_05_in_1.txt func_tests\\pos_05_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_05_out.txt) else ( echo Failed!)
pause

echo pos_06_test
app.exe m func_tests\\pos_06_in_1.txt func_tests\\pos_06_in_2.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_06_out.txt) else ( echo Failed!)
pause

echo pos_07_test
app.exe o func_tests\\pos_07_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_07_out.txt) else ( echo Failed!)
pause

echo pos_08_test
app.exe o func_tests\\pos_08_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_08_out.txt) else ( echo Failed!)
pause

echo pos_09_test
app.exe o func_tests\\pos_09_in.txt func_tests\\out.txt
if errorlevel 0 (fc func_tests\out.txt func_tests\pos_09_out.txt) else ( echo Failed!)
pause


echo NEGATIVES

echo neg_01_test
app.exe 2
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_02_test
app.exe 2 3 4 5 6
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_03_test
app.exe r 3 4 5
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_04_test
app.exe a 3 4 
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_05_test
app.exe m 3 4 
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_06_test
app.exe o 3 4 5
if errorlevel -1 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_07_test
app.exe o func_tests\\nonexisted.txt func_tests\\out.txt
if errorlevel -2 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_08_test
app.exe o func_tests\\neg_08_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_09_test
app.exe o func_tests\\neg_09_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_10_test
app.exe o func_tests\\neg_10_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_11_test
app.exe o func_tests\\neg_11_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_12_test
app.exe o func_tests\\neg_12_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_13_test
app.exe o func_tests\\neg_13_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_14_test
app.exe o func_tests\\neg_14_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_15_test
app.exe o func_tests\\neg_15_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_16_test
app.exe o func_tests\\neg_16_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_17_test
app.exe o func_tests\\neg_17_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_18_test
app.exe o func_tests\\neg_18_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_19_test
app.exe o func_tests\\neg_19_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_20_test
app.exe o func_tests\\neg_20_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_21_test
app.exe o func_tests\\neg_21_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_22_test
app.exe o func_tests\\neg_22_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_23_test
app.exe o func_tests\\neg_23_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_24_test
app.exe o func_tests\\neg_24_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_25_test
app.exe o func_tests\\neg_25_in.txt func_tests\\out.txt
if errorlevel -4 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_26_test
app.exe a func_tests\\neg_26_in_1.txt tests\\neg_26_in_2.txt func_tests\\out.txt
if errorlevel -7 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_27_test
app.exe m func_tests\\neg_27_in_1.txt tests\\neg_27_in_2.txt func_tests\\out.txt
if errorlevel -7 ( echo PASSED!) else ( echo Failed!)
pause

echo neg_28_test
app.exe o func_tests\\neg_28_in.txt func_tests\\out.txt
if errorlevel -7 ( echo PASSED!) else ( echo Failed!)
pause








