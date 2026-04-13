@echo off
cd /d D:\Desafio_ED_Emanuel

REM Try to find gcc in common locations
for %%X in (gcc.exe) do (set "FOUND=%%~$PATH:X")
if defined FOUND (
    echo GCC encontrado em %FOUND%
    gcc -o teste.exe teste.c estrutura.c requisicao.c
    if %errorlevel% == 0 (
        echo Compilacao concluida com sucesso!
        teste.exe
    ) else (
        echo Erro na compilacao
    )
) else (
    echo GCC nao encontrado no PATH
)
