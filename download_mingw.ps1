$mingwUrl = 'https://github.com/niXman/mingw-builds-binaries/releases/download/12.2.0-rt_v10-rev2/i686-12.2.0-release-posix-sjlj-rt_v10-rev2.7z'
$output = 'C:\mingw_temp.7z'
$mingwPath = 'C:\mingw_gcc'

Write-Host "Tentando baixar MinGW de repositório alternativo..."
try {
    Invoke-WebRequest -Uri $mingwUrl -OutFile $output -UseBasicParsing
    Write-Host "Download sucesso! Arquivo: $output"
} catch {
    Write-Host "Não foi possível baixar: $_"
    Write-Host "Tentando instalação local..."
}
