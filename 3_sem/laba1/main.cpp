#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::min;

#include <vector>

using std::string;
using std::strtoll;
using std::vector;

#include "point_and_rectangle.cpp"

const int base = 10;

Rectangle str_to_rect(string text)
{ // text between parentheses
    int coma_pos = 0;
    while (coma_pos < text.size() && text[coma_pos] != ',')
        ++coma_pos;
    if (coma_pos >= text.size())
    {
        cerr << "Wrong rectangle string. No comma found! String is\n"
             << text << endl;
        return Rectangle();
    }
    char *end;
    string a = text.substr(0, coma_pos);
    unsigned long long x = strtoull(a.c_str(), &end, base);
    string b = text.substr(coma_pos + 1, text.size());
    unsigned long long y = strtoull(b.c_str(), &end, base);

    return Rectangle(x, y);
}

char get_operation(string text)
{ // '*', '+' or '0' in error case
    char res = '0';
    for (char c : text)
    {
        if (c == '*' || c == '+')
        {
            res = c;
            break;
        }
    }
    return res;
}

Rectangle sum_rectangles(vector<Rectangle> t)
{
    if (t.size() == 0) {
        return Rectangle();
    }
    if (t.size() == 1)
    {
        return t[0];
    }
    Rectangle a = t[t.size() - 1];
    Rectangle b = t[t.size() - 2];
    t.pop_back();
    t.pop_back();
    t.push_back(a + b);
    return sum_rectangles(t);
}

Rectangle evaluate_expr(string expr)
{
    vector<Rectangle> sum;
    int i = 0;
    int last_close_par = -1;

    while (i < expr.size())
    {

        if (expr[i] == ')')
        {
            cerr << "Wrong parentheses in expression " << endl
                 << expr << endl;
                 break;
        }
        else if (expr[i] == '(')
        {
            char operation;
            if (last_close_par == -1)
            {
                operation = '0';
            }
            else
            {
                operation = get_operation(expr.substr(last_close_par + 1, i));
                if (operation == '0')
                {
                    cerr << "Not found operation in expr \n"
                         << expr << endl
                         << "in substring \n"
                         << expr.substr(last_close_par + 1, i) << endl
                         << last_close_par + 1 << " " << i;
                    break;
                }
            }
            int j = i + 1;
            while (expr[j] != ')' && j < expr.size())
                j++;
            last_close_par = j;
            Rectangle t = str_to_rect(expr.substr(i + 1, j));
            if (operation == '*')
            {
                Rectangle last(sum[sum.size() - 1]);
                sum.pop_back();
                sum.push_back(last * t);
            }
            else {
                sum.push_back(t);
            }

            i = j+1;
        }
        else
        {
            i++;
        }
    }
    return sum_rectangles(sum);
}

int main()
{

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // изменить стандартный поток ввода вывода

    std::string expression;
    while(std::getline(std::cin, expression)) {

    cout << expression << " = ";
    Rectangle res = evaluate_expr(expression);
    res.print();
    cout << endl;
    }
}