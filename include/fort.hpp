#ifndef LIBFORT_HPP
#define LIBFORT_HPP

#include <string>
#include <stdexcept>
#include <sstream>
#include "fort.h"

namespace fort
{

class FTableManipulator {
public:
    explicit FTableManipulator(int i)
        :value(i)
    {
    }
    friend class FTable;
private:
    int value;
};

const FTableManipulator header(0);
const FTableManipulator endl(1);
const FTableManipulator separator(2);

class FTable {
public:
    FTable()
        :table(ft_create_table())
    {
        if (table == NULL)
            throw std::runtime_error("Runtime error");
    }

    ~FTable()
    {
        ft_destroy_table(table);
    }

    std::string to_string() const
    {
        const char *str = ft_to_string(table);
        if (str == NULL)
            throw std::runtime_error("Runtime error");
        return str;
    }

    const char *c_str() const
    {
        return ft_to_string(table);
    }

    template <typename T>
    FTable &operator<<(const T &arg)
    {
        stream << arg;
        if (stream.tellp()) {
            ft_nwrite(table, 1, stream.str().c_str());
            stream = std::stringstream{};
        }
        return *this;
    }

    FTable &operator<<(const FTableManipulator &arg)
    {
        if (arg.value == header.value)
            ft_set_cell_option(table, FT_CUR_ROW, FT_ANY_ROW, FT_COPT_ROW_TYPE, FT_ROW_HEADER);
        else if (arg.value == endl.value)
            ft_ln(table);
        else if (arg.value == separator.value)
            ft_add_separator(table);
        return *this;
    }

    bool write(const char *str)
    {
        return IS_SUCCESS(ft_write(table, str));
    }

    bool write_ln(const char *str)
    {
        return IS_SUCCESS(ft_write_ln(table, str));
    }

    bool write(const std::string &str)
    {
        return write(str.c_str());
    }

    bool write_ln(const std::string &str)
    {
        return write_ln(str.c_str());
    }

#ifdef __cpp_variadic_templates
    template <typename T, typename ...Ts>
    bool write(const T &arg, const Ts &...args)
    {
        return write(arg) && write(args...);
    }

    template <typename T, typename ...Ts>
    bool write_ln(const T &arg, const Ts &...args)
    {
        if (sizeof...(args) == 0)
            return write_ln(arg);
        return write(arg) && write_ln(args...);
    }
#else /* __cpp_variadic_templates */

    template <typename T_0, typename T_1>
    bool write(const T_0 &arg_0, const T_1 &arg_1)
    {
        return write(arg_0) && write(arg_1);
    }

    template <typename T_0, typename T_1, typename T_2>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2)
    {
        return write(arg_0) && write(arg_1, arg_2);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3)
    {
        return write(arg_0) && write(arg_1, arg_2, arg_3);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4)
    {
        return write(arg_0) && write(arg_1, arg_2, arg_3, arg_4);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5)
    {
        return write(arg_0) && write(arg_1, arg_2, arg_3, arg_4, arg_5);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5, const T_6 &arg_6)
    {
        return write(arg_0) && write(arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7>
    bool write(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5, const T_6 &arg_6, const T_7 &arg_7)
    {
        return write(arg_0) && write(arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);
    }


    template <typename T_0, typename T_1>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1)
    {
        return write(arg_0) && write_ln(arg_1);
    }

    template <typename T_0, typename T_1, typename T_2>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2)
    {
        return write(arg_0) && write_ln(arg_1, arg_2);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3)
    {
        return write(arg_0) && write_ln(arg_1, arg_2, arg_3);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4)
    {
        return write(arg_0) && write_ln(arg_1, arg_2, arg_3, arg_4);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5)
    {
        return write(arg_0) && write_ln(arg_1, arg_2, arg_3, arg_4, arg_5);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5, const T_6 &arg_6)
    {
        return write(arg_0) && write_ln(arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);
    }

    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7>
    bool write_ln(const T_0 &arg_0, const T_1 &arg_1, const T_2 &arg_2, const T_3 &arg_3, const T_4 &arg_4, const T_5 &arg_5, const T_6 &arg_6, const T_7 &arg_7)
    {
        return write(arg_0) && write_ln(arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);
    }

#endif /* __cpp_variadic_templates */


private:
    FTABLE *table;
    std::stringstream stream;
};

}

#endif // LIBFORT_HPP
