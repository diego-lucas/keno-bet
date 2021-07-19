# Projeto Keno

## Compilação

Para compilar o projeto, use os seguintes comandos:

```
mkdir build && cd build
cmake ..
make
./keno ../data/arquivo_de_apostas
```

## Arquivo de apostas

Lembre de alterar o diretório do arquivo de apostas para um arquivo que você criou.<br>
O arquivo de apostas deve seguir o seguinte padrão:

```
1500.0
3
15 12 64 20 65
```

Onde cada linha significa:

1. O valor total a ser apostado.
2. A quantidade de rodadas.
3. Os numeros escolhidos (bets).
