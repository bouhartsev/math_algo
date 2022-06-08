#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string                 T_str;
typedef vector < double    >   T_row;
typedef vector < T_row     >   T_matr;
typedef T_matr                      T_fuzzy_relation;

bool    fuzzy_relation_is_reflexive( T_fuzzy_relation   const   &   fuzzy_relation )
{
    int     dim         =   fuzzy_relation.size();
    bool    bool_res    =   true;
 
    for( int  i = 0; i < dim; ++i )
    {
        bool_res    =   fuzzy_relation[i][i]    ==  1;
 
        if( !bool_res )
        {
            return  bool_res;
        }
    }
 
    return  bool_res;
}

bool    fuzzy_relation_is_antireflexive( T_fuzzy_relation   const   &   fuzzy_relation )
{
    int     dim         =   fuzzy_relation.size();
    bool    bool_res    =   true;
 
    for( int  i = 0; i < dim; ++i )
    {
        bool_res    =   fuzzy_relation[i][i]    ==  0;
 
        if( !bool_res )
        {
            return  bool_res;
        }
    }
 
    return  bool_res;
}

bool    fuzzy_relation_is_symmetric( T_fuzzy_relation   const   &   fuzzy_relation )
{
    int     dim         =   fuzzy_relation.size();
    bool    bool_res    =   true;
 
    for( int  i = 0; i < dim; ++i )
    {
        for( int  j = i + 1; j < dim; ++j )
        {
            bool_res    =   fuzzy_relation[i][j]    ==  fuzzy_relation[j][i];
 
            if( !bool_res )
            {
                return  bool_res;
            }
        }
    }
 
    return  bool_res;
}

bool    fuzzy_relation_is_antisymmetric( T_fuzzy_relation   const   &   fuzzy_relation )
{
    int     dim         =   fuzzy_relation.size();
    bool    bool_res    =   true;
 
    for( int  i = 0; i < dim; ++i )
    {
        for( int  j = i + 1; j < dim; ++j )
        {
            bool_res    =           fuzzy_relation[i][j]
                                *   fuzzy_relation[j][i]
                            ==  0;
 
            if( !bool_res )
            {
                return  bool_res;
            }
        }
    }
 
    return  bool_res;
}

bool    fuzzy_relation_is_transitive( T_fuzzy_relation   const   &   fuzzy_relation )
{
    int     dim         =   fuzzy_relation.size();
    bool    bool_res    =   true;
 
    for( int  i = 0; i < dim; ++i )
    {
        for( int  j = 0; j < dim; ++j )
        {
            for( int  k = 0; k < dim; ++k )
            {
                bool_res    =   fuzzy_relation[i][j]    >=  min
                                                                (
                                                                    fuzzy_relation[i][k],
                                                                    fuzzy_relation[k][j]
                                                                );
 
                if( !bool_res )
                {
                    return  bool_res;
                }
            }
        }
    }
 
    return  bool_res;
}

void fuzzy_relation_transitive_closure ( T_fuzzy_relation   A ) {
    int V = A.size();
    
    for (int i = 0; i < V; i++)
        for (int s = 0; s < V; s++)
            for (int t = 0; t < V; t++)
                if (A[s][i] && A[i][t]) A[s][t] = 1;
    
    cout << "транзитивное замыкание:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

template< typename  TT_func_ptr >
void    print_message_and_func_result
    (
        T_str   const               &   message,
        TT_func_ptr                     func_ptr,
        T_fuzzy_relation    const   &   fuzzy_relation
    )
{
    cout   <<  message
                <<  (
                        func_ptr( fuzzy_relation )
                            ?   "да"
                            :   "нет"
                    )
                <<  endl;
}

void    check_fuzzy_relation_and_print_result( T_fuzzy_relation   const   &   fuzzy_relation )
{
    print_message_and_func_result( "симметричность\t\t: ",      fuzzy_relation_is_symmetric,        fuzzy_relation  );
    print_message_and_func_result( "антисимметричность\t: ",    fuzzy_relation_is_antisymmetric,    fuzzy_relation  );
    print_message_and_func_result( "рефлексивность\t\t: ",      fuzzy_relation_is_reflexive,        fuzzy_relation  );
    print_message_and_func_result( "антирефлексивность\t: ",    fuzzy_relation_is_antireflexive,    fuzzy_relation  );
    print_message_and_func_result( "транзитивность\t\t: ",      fuzzy_relation_is_transitive,       fuzzy_relation  );
    fuzzy_relation_transitive_closure(fuzzy_relation);
}

int main()
{
    locale::global(locale(""));
 
    int     n   =   0;
    cin    >>  n;
 
    T_fuzzy_relation    fuzzy_relation
                            (
                                n,
                                T_row(n)
                            );
 
    for( int  i = 0; i < n; ++i )
    {
        for( int  j = 0; j < n; ++j )
        {
            cin        >>  fuzzy_relation[i][j];
        }
    }

    check_fuzzy_relation_and_print_result( fuzzy_relation );
}
