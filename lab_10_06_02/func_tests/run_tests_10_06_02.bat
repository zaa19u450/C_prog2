@echo off
cls
(cd ..)

echo POSITIVES

echo pos_01_test
app.exe < func_tests/pos_01_in.txt > func_tests/out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_01_out.txt) else ( echo Failed!)
pause

echo pos_02_test
app.exe < func_tests/pos_02_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_02_out.txt) else ( echo Failed!)
pause

echo pos_03_test
app.exe < func_tests/pos_03_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_03_out.txt) else ( echo Failed!)
pause

echo pos_04_test
app.exe < func_tests\pos_04_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_04_out.txt) else ( echo Failed!)
pause

echo pos_05_test
app.exe < func_tests\pos_05_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_05_out.txt) else ( echo Failed!)
pause

echo pos_06_test
app.exe < func_tests\pos_06_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_06_out.txt) else ( echo Failed!)
pause

echo pos_07_test
app.exe < func_tests\pos_07_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_07_out.txt) else ( echo Failed!)
pause

echo pos_08_test
app.exe < func_tests\pos_08_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_08_out.txt) else ( echo Failed!)
pause

echo pos_09_test
app.exe < func_tests\pos_09_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_09_out.txt) else ( echo Failed!)
pause

echo pos_10_test
app.exe < func_tests\pos_10_in.txt > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_10_out.txt) else ( echo Failed!)
pause

echo NEGATIVES

echo neg_01_test
app.exe < func_tests\neg_01_in.txt > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_01_out.txt
pause

echo neg_02_test
app.exe < func_tests\neg_02_in.txt > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_02_out.txt
pause

echo neg_03_test
app.exe < func_tests\neg_03_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_03_out.txt
pause

echo neg_04_test
app.exe < func_tests\neg_04_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_04_out.txt
pause

echo neg_05_test
app.exe < func_tests\neg_05_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_05_out.txt
pause


echo neg_06_test
app.exe < func_tests\neg_06_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_06_out.txt
pause

echo neg_07_test
app.exe < func_tests\neg_07_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_07_out.txt
pause

echo neg_08_test
app.exe < func_tests\neg_08_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_08_out.txt
pause

echo neg_09_test
app.exe < func_tests\neg_09_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_09_out.txt
pause

echo neg_10_test
app.exe < func_tests\neg_10_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_10_out.txt
pause

echo neg_11_test
app.exe < func_tests\neg_11_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_11_out.txt
pause

echo neg_12_test
app.exe < func_tests\neg_12_in.txt > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_12_out.txt
pause

echo neg_13_test
app.exe < func_tests\neg_13_in.txt > func_tests\out.txt
if errorlevel == -5 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_13_out.txt
pause

echo neg_14_test
app.exe < func_tests\neg_14_in.txt > func_tests\out.txt
if errorlevel == -5 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_14_out.txt
pause

echo neg_15_test
app.exe < func_tests\neg_15_in.txt > func_tests\out.txt
if errorlevel == -5 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_15_out.txt
pause


