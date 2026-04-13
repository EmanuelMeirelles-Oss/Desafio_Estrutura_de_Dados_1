$mingwPath = 'C:\mingw-w64'
$url = 'https://github.com/brechtsanders/winlibs_mingw/releases/download/12.1.0-15.0.1-10.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-12.1.0-mingw-w64-10.0.0-r5.zip'
$output = 'C:\mingw.zip'

Write-Host "Baixando MinGW..."
try {
    (New-Object System.Net.WebClient).DownloadFile($url, $output)
    Write-Host "Extraindo..."
    Expand-Archive -Path $output -DestinationPath $mingwPath -Force
    Write-Host "Adicionando ao PATH..."
    $env:PATH += ";$mingwPath\mingw64\bin"
    [Environment]::SetEnvironmentVariable("PATH", $env:PATH, [System.EnvironmentVariableTarget]::User)
    Write-Host "MinGW instalado com sucesso em $mingwPath"
} catch {
    Write-Host "Erro: $_"
}
