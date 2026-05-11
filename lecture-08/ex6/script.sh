#!/bin/bash

number1=$1
operator=$2
number2=$3

if [[ number2 -eq 0 ]]; then
    echo "Invalid divisor"
else
    case $2 in
        +)
            echo "Result: $(( number1 + number2 ))"
        ;;

        -)
            echo "Result: $(( number1 - number2 ))"
        ;;

        x)
            echo "Result: $(( number1 * number2 ))"
        ;;

        /)
            echo "Result: $(( number1 / number2 ))"
        ;;

        *)
            echo "Unknown command"
        ;;
    esac
fi