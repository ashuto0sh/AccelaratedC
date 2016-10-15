template <typename In>                                                                                        
void P(In b, In e, const std::string& delm = "\n") {                                                          
    typedef typename std::iterator_traits<In>::value_type value_type;                                         
    std::copy(b, e, std::ostream_iterator<value_type>(std::cout, delm.c_str()));                              
} 
