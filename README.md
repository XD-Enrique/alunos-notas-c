# 🎓 Sistema de Gerenciamento de Alunos em C

Este é um programa simples feito em linguagem C que permite cadastrar até 50 alunos, registrando **nome**, **idade** e **nota**. Com esses dados, o sistema calcula a média da turma, identifica o aluno com a maior nota e oferece um menu para visualizar:

- ✅ Todos os alunos
- 🟢 Apenas os aprovados (nota ≥ 6.0)
- 🔴 Apenas os reprovados (nota < 6.0)

## 🚀 Funcionalidades

- Cadastro de alunos (nome, idade, nota)
- Cálculo da média da turma
- Detecção da maior nota
- Menu interativo para visualização
- Validação da quantidade de alunos
- Interface limpa com `system("clear")`

## 🧪 Exemplo de saída

Veja o conteúdo da pasta `/exemplos/exemplo_saida.txt`

## 🧠 Lógica usada

- Vetores para armazenar os dados dos alunos
- `fgets()` + `strcspn()` para capturar o nome corretamente
- Laços `for` para percorrer e processar os dados
- Função separada para cálculo da média
- Estrutura `switch` para menu interativo

## 📦 Compilação e execução

Compile usando `gcc`:

```bash
gcc main.c -o alunos
./alunos
```

## 💡 Melhorias futuras

- Salvar os dados em arquivo `.txt`
- Ordenar por nota ou nome
- Suporte a mais alunos com alocação dinâmica
