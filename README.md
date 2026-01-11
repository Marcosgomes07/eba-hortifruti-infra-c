# 🍎 Eba Hortifruti – Sistema de Gerenciamento em C
<img loading="lazy" src="http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge"/>

## Tópicos

- Descrição do Projeto  
- Contexto Acadêmico  
- Funcionalidades  
- Classificação do Sistema (CRUD)  
- Pré-requisitos  
- Como Rodar a Aplicação  
- Tecnologias Utilizadas  

---

## Descrição do Projeto

Projeto acadêmico desenvolvido em **linguagem C** durante o **primeiro semestre da graduação**, com o objetivo de simular a infraestrutura básica de TI de um hortifruti fictício chamado **Eba Hortifruti**.

O sistema opera em ambiente **console** e permite o gerenciamento de produtos (frutas), além de simular o funcionamento de um **caixa**, aplicando conceitos fundamentais de programação estruturada, validação de dados e organização de código.

---

## Contexto Acadêmico

- **Curso:** Graduação em Análise e Desenvolvimento de Sistemas 
- **Semestre:** 1º semestre  
- **Disciplina:** Introdução à Programação / Algoritmos  
- **Linguagem:** C  
- **Tipo:** Projeto acadêmico  

---

## Funcionalidades

### Controle de Acesso
- Sistema de login com usuário e senha
- Dois perfis de acesso:
  - **Estação (Gerenciamento)**
  - **Caixa (Vendas)**
- Entrada de senha com caracteres ocultos (`*`)

### Gerenciamento de Produtos
- Cadastro de novos produtos (frutas)
- Listagem de produtos cadastrados
- Alteração de preço e tipo de venda
- Validação de entradas:
  - Nome apenas com letras e espaços
  - Preço positivo
  - Tipo de venda (`unidade` ou `kg`)
- Limite máximo de 10 produtos

### Caixa
- Seleção de produtos disponíveis
- Definição de quantidade
- Cálculo automático do valor total da compra
- Exibição de resumo da venda ao final

---

## Classificação do Sistema (CRUD)

O sistema pode ser classificado como um **CRUD parcial**, pois implementa as seguintes operações:

- **Create (C):** Cadastro de produtos  
- **Read (R):** Listagem e consulta de produtos  
- **Update (U):** Alteração de dados dos produtos  

Além do CRUD, o projeto inclui um **módulo de caixa**, responsável por regras de negócio relacionadas à venda de produtos.

---

## Pré-requisitos

- Sistema operacional compatível com C
- Compilador GCC
- Terminal / Prompt de Comando

> ⚠️ O projeto utiliza a biblioteca `conio.h`, podendo exigir ambiente Windows ou compiladores compatíveis (ex.: MinGW).

---

## Como Rodar a Aplicação

Clone ou baixe o repositório, Compile com GCC e Execute pelo terminal

## Tecnologias Utilizadas

Linguagem: `C`

Compilador: `GCC`
