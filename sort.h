#pragma once
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include "array.h"
#include "stack.h"

using namespace std;

inline int precedence(string op) {
    if (op == "u-") return 5;
    if (op == "sin" || op == "cos") return 5;
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    return 0;
}

inline bool isLeftAssoc(string op) {
    if (op == "^") return false;
    if (op == "u-") return false;
    if (op == "sin" || op == "cos") return false;
    return true;
}

inline bool isNumber(string s) {
    if (s.empty()) return false;
    bool dot = false;
    for (char c : s) {
        if (c == '.') {
            if (dot) return false;
            dot = true;
        }
        else if (!isdigit((unsigned char)c)) return false;
    }
    return true;
}

inline Array splitBySpaces(string line) {
    Array res;
    istringstream iss(line);
    string token;
    while (iss >> token) res.push(token);
    return res;
}

inline Array shuntingYardSimple(Array tokens) {
    Array output;
    Stack ops;
    string prev = "";

    for (int i = 0; i < tokens.getSize(); ++i) {
        string t = tokens.get(i);

        if (isNumber(t)) {
            output.push(t);
            prev = "number";
            continue;
        }

        if (t == "(") {
            ops.push(t);
            prev = "(";
            continue;
        }

        if (t == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push(ops.top()); ops.pop();
            }
            if (ops.empty()) throw runtime_error("Mismatched parentheses");
            ops.pop();
            if (!ops.empty()) {
                string top = ops.top();
                if (top == "sin" || top == "cos") {
                    output.push(top); ops.pop();
                }
            }
            prev = ")";
            continue;
        }

        if (t == "sin" || t == "cos") {
            ops.push(t);
            prev = "func";
            continue;
        }

        if (t == "+" || t == "-" || t == "*" || t == "/" || t == "^") {
            string op = t;
            if (t == "-") {
                if (prev == "" || prev == "(" || prev == "op") {
                    op = "u-";
                }
            }

            while (!ops.empty()) {
                string o2 = ops.top();
                if (o2 == "(") break;
                int p1 = precedence(op);
                int p2 = precedence(o2);
                if (p2 > p1 || (p1 == p2 && isLeftAssoc(op))) {
                    output.push(o2);
                    ops.pop();
                }
                else break;
            }
            ops.push(op);
            prev = "op";
            continue;
        }

        throw runtime_error("Unknown token: " + t);
    }

    while (!ops.empty()) {
        if (ops.top() == "(" || ops.top() == ")") throw runtime_error("Mismatched parentheses");
        output.push(ops.top()); ops.pop();
    }

    return output;
}
