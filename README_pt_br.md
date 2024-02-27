# minitalk

To access the English version of this README [click here](https://github.com/LeonardoSabar/Minitalk/blob/master/README.md).

<p align="center">
<img src="https://github.com/LeonardoSabar/Minitalk/blob/master/minitalk.gif" width="800px" alt="mandatory"/><br>
</p>

## Descrição

O minitalk é um projeto de programação elaborado em Linguagem C, onde os estudantes da escola 42 criam um sistema de comunicação cliente-servidor usando sinais UNIX.
O cliente envia uma mensagem de texto para o servidor codificando-a em binário e enviando-a bit a bit usando sinais. Este projeto ajuda os estudantes a entender os conceitos de manipulação de sinais e comunicação entre processos.

## Estilo de código

O estilo de código usado neste projeto é o [Norminette](https://github.com/42School/norminette) criado pela escola 42 e utilizado em todos os projetos relacionados a ANSI C no contexto da escola.


<br>


## Instalação

Este projeto usa a biblioteca externa Libft e printf desenvolvida no currículo da escola 42, para clonar este projeto e esta biblioteca, use o comando:

```sh
git clone --recursive git@github.com:LeonardoSabar/minitalk.git
```

**<em> Este comando irá clonar o projeto e o submódulo Libft  </em>**


</br>

Para compilar a parte **obrigatória** do projeto use:
```sh
make
```

Para compilar a parte **bônus** do projeto use:

```sh
make bonus
```

## Uso

Depois de compilar o projeto, os arquivos executáveis com os nomes **server** e **client** serão criados. Primeiro, você deve executar o arquivo .server para gerar o PID e, em seguida, executar o arquivo .client (de preferência em um novo terminal, paralelo ao .server), juntamente com o PID e a mensagem como argumentos:

Exemplos:

```sh
./server
```

```sh
./client "PID NUMBER" "MESSAGE TO NE SENT"
```

**<em> Se a mensagem a ser enviada for uma frase, deve-se usar aspas para encaminhá-la como um único argumento.</em>**

## Agradecimentos

A todos os meus colegas da escola 42 SP, que me ajudaram durante o desenvolvimento deste projeto.
