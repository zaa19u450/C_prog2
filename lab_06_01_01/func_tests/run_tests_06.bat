@echo off
cls
app.exe films.txt > out.txt
fc out.txt neg_01_out.txt
pause
app.exe films.txt year CasinoRoyale toomany > out.txt
fc out.txt neg_02_out.txt
pause
app.exe films.txt whatever > out.txt
fc out.txt neg_03_out.txt
pause
app.exe films.txt title 12345678901234567890123456 > out.txt
fc out.txt neg_04_out.txt
pause
app.exe films.txt name 12345678901234567890123456 > out.txt
fc out.txt neg_05_out.txt
pause
app.exe films.txt year two > out.txt
fc out.txt neg_06_out.txt
pause
app.exe films.txt year -2020 > out.txt
fc out.txt neg_07_out.txt
pause
app.exe films.txt year 100000 > out.txt
fc out.txt neg_08_out.txt
pause



app.exe no.txt year > out.txt
fc out.txt neg_09_out.txt
pause
app.exe neg_10_in.txt year > out.txt
fc out.txt neg_10_out.txt
pause
app.exe neg_11_in.txt year > out.txt
fc out.txt neg_11_out.txt
pause
app.exe neg_12_in.txt year > out.txt
fc out.txt neg_12_out.txt
pause
app.exe neg_13_in.txt year > out.txt
fc out.txt neg_13_out.txt
pause
app.exe neg_14_in.txt year > out.txt
fc out.txt neg_14_out.txt
pause
app.exe neg_15_in.txt year > out.txt
fc out.txt neg_15_out.txt
pause
app.exe neg_16_in.txt year > out.txt
fc out.txt neg_16_out.txt
pause
app.exe neg_17_in.txt year > out.txt
fc out.txt neg_17_out.txt
pause



app.exe pos_01_in.txt year > out.txt
fc out.txt pos_01_out.txt
pause
app.exe pos_02_in.txt title > out.txt
fc out.txt pos_02_out.txt
pause
app.exe pos_03_in.txt name > out.txt
fc out.txt pos_03_out.txt
pause
app.exe pos_04_in.txt year > out.txt
fc out.txt pos_04_out.txt
pause
app.exe pos_05_in.txt year > out.txt
fc out.txt pos_05_out.txt
pause
app.exe pos_06_in.txt year > out.txt
fc out.txt pos_06_out.txt
pause


app.exe pos_07_in.txt title Nobody > out.txt
fc out.txt pos_07_out.txt
pause
app.exe pos_08_in.txt name Nobody > out.txt
fc out.txt pos_08_out.txt
pause
app.exe pos_09_in.txt year 2000 > out.txt
fc out.txt pos_09_out.txt
pause
app.exe pos_10_in.txt year 2019 > out.txt
fc out.txt pos_10_out.txt
pause
app.exe pos_11_in.txt name Darabont > out.txt
fc out.txt pos_11_out.txt
pause
app.exe pos_12_in.txt title Avatar > out.txt
fc out.txt pos_12_out.txt
pause
app.exe pos_13_in.txt title "Shawshank Redemption" > out.txt
fc out.txt pos_13_out.txt
pause
app.exe pos_14_in.txt name hahn > out.txt
fc out.txt pos_14_out.txt
pause
app.exe pos_15_in.txt name > out.txt
fc out.txt pos_15_out.txt
pause



