
from functools import lru_cache
from typing import AnyStr


def find_operators(expression):
    indices = []
    for i, char in enumerate(expression):
        if char in ["+", "-", "*"]:
            indices.append(i)
    return indices


def apply(a, b, operator):
    if operator == "+":
        return a + b
    elif operator == "-":
        return a - b
    elif operator == "*":
        return a * b
    raise ValueError()


@lru_cache(maxsize=None)
def top_down(expression):
    operators = find_operators(expression)
    # base case
    if len(operators) == 0:
        return int(expression), int(expression)
    # recursive case
    max_val = -float("inf")
    min_val = float("inf")
    for idx in operators:
        operator = expression[idx]
        l_max, l_min = top_down(expression[:idx])
        r_max, r_min = top_down(expression[idx+1:])
        vals = [apply(l_max, r_max, operator),
                apply(l_min, r_max, operator),
                apply(l_max, r_min, operator),
                apply(l_min, r_min, operator)]
        max_val = max(max_val, *vals)
        min_val = min(min_val, *vals)

    return max_val, min_val


@lru_cache(maxsize=None)
def top_down_with_parentheses(expression):
    operators = find_operators(expression)
    # base case
    if len(operators) == 0:
        return int(expression), expression, int(expression), expression
    # recursive case
    max_val = -float("inf")
    min_val = float("inf")
    expr_min_ret = ""
    expr_max_ret = ""
    for idx in operators:
        operator = expression[idx]
        l_max, expr_l_max, l_min, expr_l_min = top_down_with_parentheses(
            expression[:idx])
        r_max, expr_r_max, r_min, expr_r_min = top_down_with_parentheses(
            expression[idx+1:])

        vals = [apply(l_max, r_max, operator),
                apply(l_min, r_max, operator),
                apply(l_max, r_min, operator),
                apply(l_min, r_min, operator)]
        exprs = [(expr_l_max, expr_r_max),
                 (expr_l_min, expr_r_max),
                 (expr_l_max, expr_r_min),
                 (expr_l_min, expr_r_min)]

        if max(vals) > max_val:
            max_val = max(vals)
            for i, val in enumerate(vals):
                if max_val == val:
                    expr_max_ret = f"({exprs[i][0]}{operator}{exprs[i][1]})"
        if min(vals) < min_val:
            min_val = min(vals)
            for i, val in enumerate(vals):
                if max_val == val:
                    expr_min_ret = f"({exprs[i][0]}{operator}{exprs[i][1]})"

    return max_val, expr_max_ret, min_val, expr_max_ret


input_str = input()
ans = top_down(input_str)
big = max(ans)
print(ans)
ans_with_paren = top_down_with_parentheses(input_str)
print(ans_with_paren)
