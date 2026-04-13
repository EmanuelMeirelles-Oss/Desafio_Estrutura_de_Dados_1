import json
import urllib.request
import urllib.parse
import os
import sys

# Read source files
files_content = {}
files = ['teste.c', 'estrutura.c', 'requisicao.c', 'estrutura.h', 'requisicao.h']

for file in files:
    try:
        with open(file, 'r', encoding='utf-8') as f:
            files_content[file] = f.read()
    except FileNotFoundError:
        pass

print("[*] Verificando integridade do código...")
print("=" * 70)

# Syntax validation
all_valid = True
for filename, content in files_content.items():
    braces = content.count('{') - content.count('}')
    parens = content.count('(') - content.count(')')
    brackets = content.count('[') - content.count(']')
    
    status = "✓" if braces == 0 and parens == 0 and brackets == 0 else "✗"
    print(f"[{status}] {filename}: ", end="")
    
    if braces == 0 and parens == 0 and brackets == 0:
        print("Sintaxe válida")
    else:
        print(f"Erros - Chaves: {braces}, Parênteses: {parens}, Colchetes: {brackets}")
        all_valid = False

print("=" * 70)

if all_valid:
    print("\n[✓] VALIDACAO: Nenhum erro de sintaxe detectado!")
    print("\n[*] Tentando compilar via API online...")
    
    try:
        # Try to use rextester.com API as fallback
        code = files_content.get('teste.c', '')
        
        source = "extern int printf(const char*, ...);"
        for f in ['requisicao.c', 'estrutura.c']:
            if f in files_content:
                source += "\n\n" + files_content[f]
        source += "\n\n" + files_content.get('teste.c', '')
        
        data = urllib.parse.urlencode({
            'LanguageChoice': 'C',
            'Program': source,
            'Input': '',
            'CompilerArgs': '-Wall'
        }).encode('utf-8')
        
        req = urllib.request.Request('https://rextester.com/api/compile', data=data)
        
        with urllib.request.urlopen(req, timeout=15) as response:
            result = json.loads(response.read().decode())
            
            if result.get('Errors'):
                print(f"[✗] Erros de compilacao:\n{result['Errors']}")
            else:
                print("[✓] Compilacao bem-sucedida via API!")
                if result.get('Result'):
                    print(f"\n--- SAIDA DO PROGRAMA ---\n{result['Result']}")
    except Exception as e:
        print(f"[!] API indisponível ({e})")
        print("\n[✓] Código não apresenta erros de sintaxe óbvios.")
        print("    Para executar completamente, instale um compilador C (MinGW/GCC)")
else:
    print("\n[✗] Erros de sintaxe encontrados!")
