# 🧑‍🏫 Sistema de Gerenciamento de Alunos em C

Este programa em C permite **cadastrar, listar e analisar o desempenho de alunos** com base em suas notas.  
Ele é um exemplo prático de manipulação de **estruturas, vetores, funções e menus interativos**.

---

## ⚙️ Funcionalidades

- Cadastro de até **50 alunos**, com:
  - Nome  
  - Idade  
  - Nota  
- Cálculo automático da **média da turma**  
- Identificação do **aluno com a maior nota**  
- Exibição filtrada:
  - Todos os alunos  
  - Apenas aprovados (nota ≥ 6.0)  
  - Apenas reprovados (nota < 6.0)  
- Menu interativo e interface limpa (compatível com Windows e Linux)

---

## 🧩 Estrutura do Código

O programa foi dividido em funções para melhor organização:

- `cadastrarAlunos()` → Lê e armazena os dados dos alunos  
- `mostrarAlunos()` → Exibe todos os alunos e seus status  
- `mostrarAprovados()` / `mostrarReprovados()` → Filtram os resultados  
- `calcularMedia()` → Calcula a média geral da turma  
- `indiceMaiorNota()` → Identifica o aluno com maior nota  
- `limparTela()` → Limpa o terminal de forma multiplataforma  

---
