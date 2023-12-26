/*
///// This is my final project codes;
///// I utilize "string" to store a integer which can have arbitrary length;
///// My calss name is bigint, which keeps the same with the project requirement.
///// I have many functions to test if input is an integer, if it is negative, and many calculation functions to
///// realize "+=", "-=", "*=", "/=", "+", "-", "*", "/";
///// Besides, I also define some logistic function to realize comparison and other functions like ">=", ">", "<=", 
///// "<", "==", "!=", "-", "=";
///// I never use any functions on "int" or something like that, My functions' objecta are only strings;
///// I have used many algorithms (all them are considered by my own, maybe they exist on the website), and I program those codes
///// to realize them, moreover I debug them for a long time. For instance, functions "*=" and "/="( more details can be seen in the 
///// Readme.md).
*/
#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
using namespace std;
class bigint
{
    public:
        /// @brief  this is an initial function, the default value is "0";
        bigint();

        /// @brief  this function is to give a new string to the existed integer;
        /// @param  string is a new string input;
        bigint(const string);

        /// @brief    this function can test if the input integer is negative, because the negative has the symbol "-";
        /// @return   return value is a "bool", if the input is negative, return "true", otherwise "false";
        bool is_negative() const;

        /// @brief this function can give the string with symbol "-" or not, like "13156464" or "-646845313".
        /// @return return value is the string
        string get_integer() const;

        /// @brief this function can give the string without symbol "-", if the integer is bigint("-23516846"), the result is "23516846"
        /// @return return value is the string
        string get_pure_figures() const;

        /// @brief this function gives a new string to existed private "value", besides it can also test if the input is an integer, moreover,
        ///        this function can record the number of invalid "0" and delete them, such as "0000152"->"152" and "-0025"->"-25"
        /// @param  string is an input string
        void set(const string);

        /// @brief this function realize that a bigger integer minus a smaller integer
        /// @param min_number input integer
        /// @return return value is a string which stores the minus result
        string two_positives_max_minus_min(const bigint min_number) const;

        /// @brief this function can add a smaller integer to a bigger integer
        /// @param min_number input integer
        /// @return return value is a string which stores the added result
        string two_positives_max_plus_min(const bigint min_number) const;

        /// @brief function "+="
        bigint& operator +=(const bigint&);

        /// @brief function "-="
        bigint& operator -=(const bigint&);

        /// @brief function "*="
        bigint& operator *=(const bigint&);

        /// @brief function "/="
        bigint& operator /=(const bigint&);

        /// @brief logistic function "="
        /// @return return the new integer
        bigint& operator =(const bigint&);

        /// @brief logistic function "-"
        /// @return return the inverse number like "1"->"-1" and "-1"->"1"
        bigint operator -() const;

        /// @brief overload "<<" to store new output in "out", the ouput includs "length", "whether it is negative" and "the number",
        ///        besides if the integer isn't an integer, throw invalid_argument, then the output integer can be shown with "," every
        ///        three valid figures. For instance, "0025689"->25,689, "-0015223"->-15,223
        friend ostream& operator<<(ostream&, const bigint&);

        /// @brief logistic function ">"
        friend bool operator >(bigint, const bigint&);

        /// @brief logistic function ">="
        friend bool operator >=(bigint, const bigint&);

        /// @brief logistic function "=="
        friend bool operator ==(bigint, const bigint&);

        /// @brief logistic function "!="
        friend bool operator !=(bigint, const bigint&);

        /// @brief logistic function "<"
        friend bool operator <(bigint, const bigint&);

        /// @brief logistic function "<="
        friend bool operator <=(bigint, const bigint&);
    private:
        string value = "0";
};

bigint operator +(bigint first_number, const bigint& second_number);
bigint operator -(bigint first_number, const bigint& second_number);
bigint operator *(bigint first_number, const bigint& second_number);
bigint operator /(bigint first_number, const bigint& second_number);

bool operator >(bigint first_number, const bigint& second_number);
bool operator >=(bigint first_number, const bigint& second_number);
bool operator ==(bigint first_number, const bigint& second_number);
bool operator !=(bigint first_number, const bigint& second_number);
bool operator <(bigint first_number, const bigint& second_number);
bool operator <=(bigint first_number, const bigint& second_number);

/// @brief test if the integer is negative, mainly according to value[0]
bool bigint::is_negative() const
{   
    if(value[0]=='-')
        return true;
    return false;
}

/// @brief set a new integer string to value, of course it tests if the input string is an integer, and records how many the invalid "0" are, 
///        delete them. The method is to test every element in a string till the figure(not "0") has been found.
/// @param input_number 
void bigint::set(const string input_number)
{   
    int input_length = input_number.length();
    string update_input;
    int forward_zero_number = 0;
    int flag = 0; /////// 1: negative 0:not negative, using "int" because this can be added to track element location of string

    //////////// To know how many zeros in front of the first valid figure
    for(size_t i = 0;i<input_length;i++)
    {
        if(i==0 && input_number[i] == '-')
        {
            flag = 1;
            continue;
        }
        if(input_number[i] != '0')
        {
            break;
        }
        forward_zero_number++;
    }
    //////////// transfer integer to value
    if(forward_zero_number==0 || forward_zero_number==(input_length-flag))
    {
        value = input_number;
    }
    if(forward_zero_number>0 && forward_zero_number<(input_length-flag))
    {
        update_input.resize(input_length-forward_zero_number);
        int location = 0;
        if(flag == 1)
        {
            update_input[0] = '-';
            location = 1;
        }
        for(size_t jj=(flag+forward_zero_number);jj<input_length;jj++)
        {
            update_input[location] = input_number[jj];
            location++;
        }
        value = update_input;
    }

    ////// test if it is an integer
    int string_length = value.length();
    for(size_t k=0;k<string_length;k++)
    {    
        if(k==0 && value[k] == '-')
        {
            continue;
        }
        if(!isdigit(value[k]))
        {
            throw invalid_argument("The number you input is not an integer! "); 
        }
    }    
}

/// @brief initial function
bigint::bigint()
{
    set("0");
}

/// @brief set a new string to value
/// @param input_number 
bigint::bigint(const string input_number)
{
    set(input_number);
}

/// @brief get the value string
string bigint::get_integer() const
{
    return value;
}

/// @brief get the string without symbol "-"
string bigint::get_pure_figures() const
{
    if(value[0]=='-')
    {
        string value0;
        value0.resize(value.length()-1);
        for(size_t i=0;i<value0.length();i++)
        {
            value0[value0.length()-i-1] = value[value.length()-i-1];
        }
        return value0;
    }
    else
    {
        return value;
    }
}

/// @brief overload "<<"
/// @return the result will be shown with "," every three figures
ostream& operator<<(ostream& out, const bigint& input_number)
{
    string string_value = input_number.get_integer();
    int string_length = string_value.length();
    out<<"length: "<<string_length<<endl;
    if(input_number.is_negative())
    {
        out<<"The number is negative !"<<endl;
        out<<"The number is -";
        int count = 3 - ((string_length-1)%3);
        if(count == 3)
        {
            count = 0;
        }
        for(size_t i=1;i<string_length;i++)
        {   
            count++;
            out<<string_value[i];
            if(count == 3 && i<string_length-1)
            {
                count = 0;
                out<<',';
            }
        }
        out<<endl;
    }
    else
    {
        out<<"The number you input is not negative !"<<endl;
        out<<"The number is ";
        int count = 3 - (string_length%3);
        if(count == 3)
        {
            count = 0;
        }
        for(size_t i=0;i<string_length;i++)
        {   
            count++;
            out<<string_value[i];
            if(count == 3 && i<string_length-1)
            {
                count = 0;
                out<<',';
            }
        }
        out<<endl;
    }
    return out;
}

/// @brief compare two integers, using "for" loop to compare two strings
/// @param first_number in front of ">"
/// @param second_number behind ">"
bool operator >(bigint first_number, const bigint& second_number)
{
    string value1 = first_number.get_integer();
    string value2 = second_number.get_integer();

    /////// if one is negative while another is not
    if(value1[0]=='-'&&value2[0]!='-')
    {
        return false;
    }
    else if(value1[0]!='-'&&value2[0]=='-')
    {
        return true;
    }
    /////// if they both are negative
    else if(value1[0]=='-'&&value2[0]=='-')
    {
        if(value1.length()<value2.length())
        {
            return true;
        }
        else if(value1.length()>value2.length())
        {
            return false;
        }
        else
        {
            for(size_t i=1;i<value1.length();i++)
                if(value1[i]>value2[i])
                {
                    return false;
                }
                else if(value1[i]<value2[i])
                {
                    return true;
                }
            return false;
        }
    }
    /////// if they both aren't negative
    else
    {
        if(value1.length()<value2.length())
        {
            return false;
        }
        else if(value1.length()>value2.length())
        {
            return true;
        }
        else
        {
            for(size_t i=0;i<value1.length();i++)
                if(value1[i]>value2[i])
                {
                    return true;
                }
                else if(value1[i]<value2[i])
                {
                    return false;
                }
            return false;
        }
    }
}

/// @brief compare two integers using ">"
/// @param first_number in front of "<"
/// @param second_number behind "<"
bool operator ==(bigint first_number, const bigint& second_number)
{
    return (!(first_number>second_number)) && (!(second_number>first_number));
}

/// @brief compare two integers using ">" and "=="
/// @param first_number in front of ">="
/// @param second_number behind ">="
bool operator >=(bigint first_number, const bigint& second_number)
{
    return (first_number>second_number) || (first_number==second_number);
}

/// @brief compare two integers using "=="
/// @param first_number in front of "!="
/// @param second_number behind "!="
bool operator !=(bigint first_number, const bigint& second_number)
{
    return !(first_number==second_number);
}

/// @brief compare two integers ">"
/// @param first_number in front of "<"
/// @param second_number behind "<"
bool operator <(bigint first_number, const bigint& second_number)
{
    return (second_number>first_number);
}

/// @brief compare two integers using "<" and "=="
/// @param first_number in front of "<="
/// @param second_number behind "<="
bool operator <=(bigint first_number, const bigint& second_number)
{
    return (first_number<second_number) || (first_number==second_number);
}

/// @brief a bigger integer minus a smaller integer, using "for" loop to substract the element in every location,
///        "if_borrow" means there is a need to borrow "1" from the former location.
string bigint::two_positives_max_minus_min(const bigint min_number) const
{
    string new_value = min_number.get_integer();
    string update_num;
    int Max_num_length = value.length();
    int min_num_length = new_value.length();
    update_num.resize(Max_num_length);
    int if_borrow = 0;
    int min_num_figure_i;
    int max_num_figure_i;
    int substract_num = 0;
    for(size_t i=0;i<Max_num_length;i++)
    {
        if(i<=min_num_length-1)
        {
            min_num_figure_i = new_value[min_num_length - i - 1] - '0';
        }
        else
        {
            min_num_figure_i = 0;
        }

        max_num_figure_i = value[Max_num_length - i - 1] - '0';
        substract_num = max_num_figure_i - min_num_figure_i - if_borrow;
        if(substract_num>=0)
        {
            update_num[Max_num_length - i - 1] = substract_num + '0';
            if_borrow = 0;
            continue;
        }
        else if(substract_num<0)
        {
            substract_num = -substract_num;
            substract_num = 10-substract_num%10;
            if_borrow = 1;
            update_num[Max_num_length - i - 1] = substract_num + '0';
            continue;
        }
    }

    bigint output_number(update_num);
    update_num = output_number.get_integer();
    return update_num;
}

/// @brief add a smaller integer to a bigger one, also using "for" loop to plus elements in every location,
///        "if_add" means there is a need to add "1" in the former location
string bigint::two_positives_max_plus_min(const bigint min_number) const
{
    string new_value = min_number.get_integer();
    string update_num;
    int Max_num_length = value.length();
    int min_num_length = new_value.length();
    update_num.resize(Max_num_length+1);
    int if_add = 0;
    int min_num_figure_i;
    int max_num_figure_i;
    int add_num = 0;
    for(size_t i=0;i<=Max_num_length;i++)
    {
        if(i<=min_num_length-1)
        {
            min_num_figure_i = new_value[min_num_length - i - 1] - '0';
            max_num_figure_i = value[Max_num_length - i - 1] - '0';
        }
        else if(i == Max_num_length)
        {
            min_num_figure_i = 0;
            max_num_figure_i = 0;
        }
        else
        {
            max_num_figure_i = value[Max_num_length - i - 1] - '0';
            min_num_figure_i = 0;
        }

        add_num = max_num_figure_i + min_num_figure_i + if_add;
        if(add_num>=10)
        {
            if_add = 1;
        }
        else
        {
            if_add = 0;
        }
        add_num = add_num%10;
        update_num[Max_num_length - i] = add_num + '0';
    }

    bigint output_number(update_num);
    update_num = output_number.get_integer();
    return update_num;
}

/// @brief add two integer using functions "two_positives_max_plus_min" and "two_positives_max_minus_min", besides also using 
///        logistic functions ">=" and "is_negative()"
bigint& bigint::operator +=(const bigint& new_one)
{
    bigint first_one(value);
    if((!first_one.is_negative()) && (!new_one.is_negative()))     //////// for example: "15646" += "1064684"
    {
        if(first_one>=new_one)
        {
            string update_num = first_one.two_positives_max_plus_min(new_one);
            set(update_num);
        }
        else
        {
            string update_num = new_one.two_positives_max_plus_min(first_one);
            set(update_num);
        }
    }
    else if((!first_one.is_negative())&&(new_one.is_negative()))     /////////// for example: "16546546" += "-135146"
    {
        bigint second_one(new_one.get_pure_figures());
        if(first_one>=second_one)
        {
            string update_num = first_one.two_positives_max_minus_min(second_one);
            set(update_num);
        }
        else
        {
            string update_num0 = second_one.two_positives_max_minus_min(first_one);
            string symbol = "-";
            string update_num = update_num0.insert(0, symbol);
            set(update_num);
        }
    }
    else if((first_one.is_negative())&&(!new_one.is_negative()))     ///////// for example: "-1564684" += "164845"
    {
        bigint second_one(new_one.get_pure_figures());
        if(second_one>=first_one)
        {
            string update_num = second_one.two_positives_max_minus_min(first_one);
            set(update_num);
        }
        else
        {
            string update_num0 = first_one.two_positives_max_minus_min(second_one);
            string symbol = "-";
            string update_num = update_num0.insert(0, symbol);
            set(update_num);
        }
    }
    else      ////////////// for example: "-1656" += "-2546" -> "-" ("1656"+="2546")
    {
        bigint first_one_0(first_one.get_pure_figures());
        bigint second_one(new_one.get_pure_figures());
        if(first_one_0>=second_one)
        {
            string update_num0 = first_one_0.two_positives_max_plus_min(second_one);
            string symbol = "-";
            string update_num = update_num0.insert(0, symbol);
            set(update_num);
        }
        else
        {
            string update_num0 = second_one.two_positives_max_plus_min(first_one_0);
            string symbol = "-";
            string update_num = update_num0.insert(0, symbol);
            set(update_num);
        }
    }
    return *this;
}

/// @brief an integer minus another integer, using "+="
bigint& bigint::operator -=(const bigint& new_one)
{
    bigint first_one(value);
    if(new_one.is_negative())         ////////////// for example: "1535" -= "-444" -> "1535" += "444"
    {
        bigint second_one(new_one.get_pure_figures());
        first_one+=second_one;
        set(first_one.get_integer());
        return *this;
    }
    else                               ///////////// for example: "1535" -= "444" -> "1535" += "-444"
    {
        string update_num0 = new_one.get_integer();
        string symbol = "-";
        string update_num = update_num0.insert(0, symbol);
        bigint second_one(update_num);
        first_one+=second_one;
        set(first_one.get_integer());
        return *this;
    }
}

/// @brief using "+=" to help to realize "*=", however this function only operate string, so in every loop, I add "0" behind the number,
///        for instance, "123" *= "32": at first I callculate "123"+="123" for twice as "246", secondly I add a "0" to "123" and compute
///        "1230"+="1230" for 3 times as "3690", finally I compute the result "246" += "3690". This method is fast, because I only operate
///        strings
bigint& bigint::operator *=(const bigint& new_one)
{
    bigint zero_one(value);
    bigint first_one(zero_one.get_pure_figures());
    int flag = 0;
    if((!first_one.is_negative() && !new_one.is_negative()) || (first_one.is_negative() && new_one.is_negative()))
    {
        flag = 1;
    }

    bigint second_one(new_one.get_pure_figures());
    string new_value = second_one.get_integer();
    int count1 = 0;
    int count2 = 0;
    bigint zero_num("0");
    for(size_t i=0;i<new_value.length();i++)
    {   
        if(i==0)
        {
            bigint third_one(value);
            for(size_t j=0;j<(new_value[new_value.length()-i-1]-'0');j++)
            {   
                count1 = 1;
                zero_num+=third_one;
            }
        }
        else
        {
            string aaa;
            aaa.resize(i,'0');
            string bbb = aaa.insert(0, value);
            bigint third_one(bbb);
            for(size_t j=0;j<(new_value[new_value.length()-i-1]-'0');j++)
            {   
                count2 = 1;
                zero_num+=third_one;
            }
        }
    }

    if(flag == 1)
    {
        set(zero_num.get_integer());
    }
    else
    {
        string update_num0 = zero_num.get_integer();
        string symbol = "-";
        string update_num = update_num0.insert(0, symbol);
        set(update_num);
    }
    return *this;
}

/// @brief using "-=" to help to compute the result. I also only operate the strings which is fast. For example "123"/="3":
///        firstly, I use "1"-="3", get the result "0" and remaining "1"; secondly I combine remainning "1" and second figure "2" as 
///        "12", then "12"-="3", get the result "04" and remaining "0"; thirdly I combine remaining "0" and third figure "3" as
///        "03", then "03"-="3", get the result "041" and remaining "0". Here the loop is over, I set "041" as a value, so I get
///        result bigint("041"), the result is "41" according to function "set()"
bigint& bigint::operator /=(const bigint& new_one)
{
    bigint first_one0(value);
    bigint zero_unit;
    bigint first_one(first_one0.get_pure_figures());
    bigint second_one(new_one.get_pure_figures());
    int flag = 0;
    if((!new_one.is_negative() && !first_one0.is_negative()) || (new_one.is_negative() && first_one0.is_negative()))
    {
        flag = 1;
    }

    if(first_one==zero_unit)
    {
        set("0");
        return *this;
    }
    
    if(second_one>first_one || second_one==zero_unit)
    {
        throw invalid_argument("Cannot be divided as an integer! ");
    }
    else
    {
        string first_string = first_one.get_integer();
        string second_string = second_one.get_integer();
        int64_t first_length = first_string.length();
        int64_t second_length = second_string.length();
        int tag = 0;
        bigint result_0;
        string remain_0;
        bigint unit("1");
        bigint result_1;
        string result_0_string;

        for(size_t i=0; i<first_length; i++)
        {   
            remain_0 = remain_0 + first_string[i];
            result_1 = zero_unit;
            bigint part_first_num(remain_0);
            do
            {
                part_first_num-=second_one;
                if(part_first_num<zero_unit)
                {
                    part_first_num+=second_one;
                    break;
                }
                else
                {
                    result_1+=unit;
                }
            } while (1);
            string result_1_string = result_1.get_integer();
            result_0_string = result_0_string + result_1_string;

            part_first_num.get_integer();
            remain_0 = part_first_num.get_integer();
        }
        if(flag==0)
        {
            result_0_string = '-' + result_0_string;
        }
        set(result_0_string);
        return *this;
    } 
}

/// @brief using function "set()" to give a new integer string 
bigint& bigint::operator =(const bigint& new_one)
{
    set(new_one.get_integer());
    return *this;
}

/// @brief using "is_negative()" to test the integer to know if I should add "-" or delete "-" 
bigint bigint::operator -() const
{
    bigint first_one(value);
    if(first_one.is_negative())
    {
        string update_num = first_one.get_pure_figures();
        bigint output(update_num);
        return output;
    }   
    else
    {
        string update_num = '-' + first_one.get_pure_figures();
        bigint output(update_num);
        return output;
    }
}

/// @brief using "+=" 
bigint operator +(bigint first_number, const bigint& second_number)
{
    return first_number+=second_number;
}

/// @brief using "-=" 
bigint operator -(bigint first_number, const bigint& second_number)
{
    return first_number-=second_number;
}

/// @brief using "*=" 
bigint operator *(bigint first_number, const bigint& second_number)
{
    return first_number*=second_number;
}

/// @brief using "/=" 
bigint operator /(bigint first_number, const bigint& second_number)
{
    return first_number/=second_number;
}
