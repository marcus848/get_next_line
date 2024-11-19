# get_next_line
o projeto **get_next_line** da 42 é um exercício de leitura de um file descriptor(fd) linha por linha, fornecendo uma função `char *get_next_line(int fd)` que retornará a próxima linha a cada vez que for chamada. este readme tem como objetivo fornecer uma compreensão clara da implementação, da metodologia de teste e de como você pode executar o código fornecido em seu sistema.

## 📋 índice
- [antes de começar](#-antes-de-começar)
- [sobre](#ℹ%EF%B8%8F--sobre)
- [instalação](#%EF%B8%8F-instalação)
- [uso](#--uso)
- [bônus](#-bônus)
- [Funções do gnl](#%EF%B8%8F-funções-do-get_next_linec)
- [notas](#-notas)
- [conclusão](#-conclusão)

## 🚀 Antes de Começar

### O que é uma Variável Estática?
Uma variável estática em C é uma variável que mantém seu valor entre chamadas de função. Diferente de uma variável local, que é destruída ao final da execução da função, a variável estática mantém seu estado. No contexto do get_next_line, isso é essencial para que a função lembre de onde parou e continue a leitura do arquivo corretamente na próxima chamada.
### Função read()
A função read() é usada para ler dados de um FD. Ela recebe três parâmetros: o descritor de arquivo (fd), um buffer onde os dados serão armazenados, e o número de bytes a serem lidos. Ela retorna o número de bytes realmente lidos ou -1 em caso de erro. No get_next_line, read() é usada repetidamente até encontrar uma nova linha (`\n`) ou até o final do arquivo.

## ℹ️  sobre
a função **get_next_line** foi projetada para ler de um determinado file descriptor(fd), uma linha de cada vez, até o final do arquivo. necessário usar variável estática.

**diferença entre implementação regular e bônus:**
- **regular:**A implementação regular da get_next_line lida com um único file descriptor (fd) por vez, retornando a próxima linha do arquivo em cada chamada. Ela pode usar quantas variáveis estáticas forem necessárias para manter o estado da leitura entre chamadas. 
    ```c
    char	*get_next_line(int fd)
    {
	    static char	*line;
	    char		*current_line;

	    if (fd < 0 || buffer_size <= 0)
		    return (null);
	    if (!line)
		    line = ft_strdup("");
	    line = get_full_line(fd, line);
	    if (!line)
		    return (null);
	    current_line = find_current_line(line);
	    line = find_next_line(line);
	    return (current_line);
    }
    ```
- **bônus:** A implementação bônus lida com múltiplos file descriptors simultaneamente, utilizando uma única variável estática *line[1024] para armazenar o estado de cada descritor. Cada índice do array representa um descritor diferente, permitindo que cada descritor mantenha seu próprio progresso de leitura de forma independente. 
    ```c
    char	*get_next_line(int fd)
    {
	    static char	*line[1024];
	    char		*current_line;

	    if (fd < 0 || BUFFER_SIZE <= 0)
		    return (NULL);
	    if (!line[fd])
		    line[fd] = ft_strdup("");
	    line[fd] = get_full_line(fd, line[fd]);
	    if (!line)
		    return (NULL);
	    current_line = find_current_line(line[fd]);
	    line[fd] = find_next_line(line[fd]);
	    return (current_line);
    }
    ```
### 📋 Linked list 
Também existe uma versão alternativa do get_next_line que utiliza listas encadeadas (linked lists) para gerenciar a leitura dos dados. Para mais detalhes, você pode acessar o README específico [nesta branch](https://github.com/marcus848/get_next_line/tree/linked_list).

## ⚙️ instalação
para usar o **get_next_line**, clone o repositório e certifique-se de que você tem as seguintes dependências instaladas:

- gcc (para compilação)
- bash (para executar scripts shell)

clone o repositório com:

```bash
git clone https://github.com/marcus848/get_next_line.git gnl
```

## 🧪  uso
para facilitar os testes da função **get_next_line**, recomendamos o uso do script **tester_gnl.sh** fornecido, que permite testar a implementação de forma prática e automatizada.
é importante saber que existe dois tipos de testes, simples e intercalado(multiplos FDs - Bônus)

### 🚩 explicação das flags do `tester_gnl.sh`
o script **tester_gnl.sh** suporta as seguintes flags:
- `-bonus`: Executa o teste intercalado com múltiplos file descriptors (FDs).
- `-compile_bonus`: compila apenas a versão bônus e a executa, útil para testar funcionalidades específicas da versão bônus.
- `-compare`: compara a execução entre a versão regular e a bônus, mostrando as diferenças no comportamento com múltiplos FDs.

### 📋 exemplos de uso do `tester_gnl.sh`
- **SINTAXE:**
  ```bash
  ./tester_gnl.sh {BUFFER_SIZE} {-bonus} {-compile_bonus} {-compare}
  ```
- para compilar a versão normal e executar o teste com multiplos FDs intercalado:
  ```bash
  ./tester_gnl.sh -bonus
  ```
- para compilar a versão bonus e executar o teste simples. Definindo o BUFFER_SIZE igual a 10:
  ```bash
  ./tester_gnl.sh 10 -compile_bonus
  ```
- para compilar a versão bonus e executar o teste com multiplos FDs intercalado:
  ```bash
  ./tester_gnl.sh -compile_bonus -bonus
  ```
- para comparar as versões regular e bônus:
  ```bash
  ./tester_gnl.sh -compare
  ```
  isso permitirá ver a diferença no comportamento entre as duas versões, especialmente no que diz respeito ao suporte para múltiplos FDs.

### 🔨 usando o script `compile.sh` manualmente
caso deseje testar manualmente, você pode utilizar o script **compile.sh** para compilar os arquivos do projeto.
A flag `-compile_bonus` também pode ser usada para compilar a versão que suporta múltiplos FDs:

1. compile com o **compile.sh**:
   ```bash
   ./compile.sh 42
   ```
   ou para compilar a versão bônus:
   ```bash
   ./compile.sh 10 -compile_bonus
   ```

2. execute o arquivo gerado (`gnl.out`) para ler as linhas dos arquivos de teste:
   ```bash
   ./gnl.out
   ```
   ou, para a versão bônus:
   ```bash
   ./gnl.out -bonus
   ```

## 🎁 bônus
a versão bônus do **get_next_line** inclui suporte para ler de múltiplos descritores de arquivo simultaneamente, o que é particularmente útil ao ler dados de diferentes fluxos de entrada de forma concorrente. isso é implementado usando um array de variáveis estáticas indexadas pelo descritor de arquivo.

para testar a funcionalidade bônus, passe a flag `-bonus` durante a compilação e execução.

exemplo:
```bash
./compile.sh -compile_bonus
./gnl.out -bonus
```

## 🛠️ funções do `get_next_line.c`
### ✨ `get_next_line(int fd)`
- função principal que retorna a próxima linha do descritor de arquivo fornecido. utiliza uma variável estática para armazenar o restante do conteúdo entre chamadas consecutivas.

### 📜 `get_full_line(int fd, char *line)`
- lê do descritor de arquivo até encontrar um caractere de nova linha (`\n`) ou até o final do arquivo. atualiza o conteúdo da linha com o que foi lido.

### 🔍 `find_current_line(char *line)`
- encontra e retorna a linha atual (ou seja, o conteúdo até o primeiro `\n` ou o final da string).

### 🔄 `find_next_line(char *line)`
- atualiza a variável estática para armazenar o restante da linha após o `\n`, preparando-a para a próxima chamada da função `get_next_line`.

## 📌 notas
- a macro **buffer_size** afeta o desempenho da função. experimente com diferentes valores (por exemplo, 32, 64, 128) para ver seu impacto.
- a função **get_next_line** deve lidar com casos de borda, como ler um arquivo vazio ou lidar com linhas muito grandes.
- o tratamento de erros é implementado para gerenciar descritores de arquivo inválidos ou falhas de alocação.

### ♻️ gerenciamento de memória
a implementação garante que todas as alocações de memória sejam gerenciadas corretamente para evitar vazamentos. o uso de funções utilitárias como `ft_strjoin` e `ft_strdup` ajuda a criar novas strings sem corrupção de memória.

### 📚 dependências
as seguintes funções utilitárias são fornecidas em **get_next_line_utils.c**:
- **ft_strchr**: localiza a primeira ocorrência de um caractere em uma string.
- **ft_strlen**: calcula o comprimento de uma string.
- **ft_strdup**: duplica uma string.
- **ft_strjoin**: concatena duas strings.
- **ft_memcpy**: copia uma área de memória.

## 🎯 conclusão
a função **get_next_line** é um exercício fundamental em gerenciamento de memória e trabalho com descritores de arquivo. ela oferece um exemplo prático de como implementar uma função capaz de ler dados estruturados de arquivos, uma linha de cada vez. a parte bônus adiciona complexidade ao introduzir suporte para múltiplos descritores de arquivo, enfatizando a importância de variáveis estáticas na manutenção do estado entre chamadas de função.

sinta-se à vontade para explorar o código-fonte, modificar o tamanho do buffer e contribuir sugerindo otimizações ou soluções alternativas!


