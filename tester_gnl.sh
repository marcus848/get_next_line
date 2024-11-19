#!/bin/bash

buffer=42
bonus_flag=false
compile_bonus_flag=false
compare_flag=false

# Cores para saída
RED='\033[3;31m'
GREEN='\033[0;32m'
YELLOW='\033[3;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Parse argumentos
for arg in "$@"
do
    case $arg in
        -bonus)
            bonus_flag=true
            ;;
        -compile_bonus)
            compile_bonus_flag=true
            ;;
        -compare)
            compare_flag=true
            ;;
        *)
            if [[ $arg =~ ^[0-9]+$ ]]; then
                buffer=$arg
            fi
            ;;
    esac
done

# Compilar e executar testes
if [ "$compare_flag" = true ]; then
    echo -e "${BLUE}Compilando o regular e testando com -bonus...${NC}"
    echo -e "${RED}Nota: Como esta versão não lida com múltiplos file descriptors, as linhas podem ficar embaralhadas e erradas.${NC}"
    ./compile.sh $buffer
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Execução com objs e -bonus:${NC}"
        ./gnl.out -bonus
    else
        echo -e "${RED}Erro ao compilar com objs.${NC}"
        exit 1
    fi

    echo -e "\n${BLUE}Compilando o bonus e testando com -bonus...${NC}"
    echo -e "${YELLOW}Nota: Como esta versão lida com múltiplos file descriptors, ela consegue intercalar as linhas corretamente.${NC}"
    ./compile.sh $buffer -compile_bonus
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Execução com objsbonus e -bonus:${NC}"
        ./gnl.out -bonus
    else
        echo -e "${RED}Erro ao compilar com objsbonus.${NC}"
        exit 1
    fi
elif [ "$compile_bonus_flag" = true ]; then
    echo -e "${BLUE}Compilando o bonus...${NC}"
    ./compile.sh $buffer -compile_bonus
    if [ $? -eq 0 ]; then
        if [ "$bonus_flag" = true ]; then
	    echo -e "${YELLOW}Nota: Como esta versão lida com múltiplos file descriptors, ela consegue intercalar as linhas corretamente.${NC}"
            echo -e "${GREEN}Execução com -bonus (com objsbonus):${NC}"
            ./gnl.out -bonus
        else
            echo -e "${GREEN}Execução sem -bonus (com objsbonus):${NC}"
            ./gnl.out
        fi
    else
        echo -e "${RED}Erro ao compilar com objsbonus.${NC}"
        exit 1
    fi
elif [ "$bonus_flag" = true ]; then
    echo -e "${BLUE}Compilando o regular e testando com -bonus...${NC}"
    echo -e "${RED}Nota: Como esta versão não lida com múltiplos file descriptors, as linhas podem ficar embaralhadas e erradas.${NC}" 
    ./compile.sh $buffer
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Execução com -bonus:${NC}"
        ./gnl.out -bonus
    else
        echo -e "${RED}Erro ao compilar com -bonus.${NC}"
        exit 1
    fi
else
    echo -e "${BLUE}Compilando o regular e testando sem -bonus...${NC}"
    ./compile.sh $buffer
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Execução sem -bonus:${NC}"
        ./gnl.out
    else
        echo -e "${RED}Erro ao compilar.${NC}"
        exit 1
    fi
fi
