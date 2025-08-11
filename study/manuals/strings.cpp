============================================================
std::string — C++98 Member Functions
============================================================

[ Constructors / Destructor ]
- string()
- string(const string& str)
- string(const string& str, size_type pos, size_type n = npos)
- string(const char* s)
- string(const char* s, size_type n)
- string(size_type n, char c)
- template<class InputIterator> string(InputIterator first, InputIterator last)
- ~string()

[ Assignment ]
- string& operator=(const string& str)
- string& operator=(const char* s)
- string& operator=(char c)

[ Iterators ]
- iterator begin()
- const_iterator begin() const
- iterator end()
- const_iterator end() const
- reverse_iterator rbegin()
- const_reverse_iterator rbegin() const
- reverse_iterator rend()
- const_reverse_iterator rend() const

[ Capacity ]
- size_type size() const
- size_type length() const
- size_type max_size() const
- void resize(size_type n, char c)
- void resize(size_type n)
- size_type capacity() const
- void reserve(size_type res_arg = 0)
- bool empty() const

[ Element Access ]
- const_reference operator[](size_type pos) const
- reference operator[](size_type pos)
- const_reference at(size_type pos) const
- reference at(size_type pos)

[ Modifiers ]
- string& operator+=(const string& str)
- string& operator+=(const char* s)
- string& operator+=(char c)
- string& append(const string& str)
- string& append(const string& str, size_type pos, size_type n)
- string& append(const char* s)
- string& append(const char* s, size_type n)
- string& append(size_type n, char c)
- template<class InputIterator> string& append(InputIterator first, InputIterator last)
- void push_back(char c)
- string& assign(const string& str)
- string& assign(const string& str, size_type pos, size_type n)
- string& assign(const char* s)
- string& assign(const char* s, size_type n)
- string& assign(size_type n, char c)
- template<class InputIterator> string& assign(InputIterator first, InputIterator last)
- string& insert(size_type pos, const string& str)
- string& insert(size_type pos, const string& str, size_type subpos, size_type sublen)
- string& insert(size_type pos, const char* s)
- string& insert(size_type pos, const char* s, size_type n)
- string& insert(size_type pos, size_type n, char c)
- iterator insert(iterator p, char c)
- void insert(iterator p, size_type n, char c)
- template<class InputIterator> void insert(iterator p, InputIterator first, InputIterator last)
- string& erase(size_type pos = 0, size_type n = npos)
- iterator erase(iterator p)
- iterator erase(iterator first, iterator last)
- string& replace(size_type pos, size_type n, const string& str)
- string& replace(size_type pos, size_type n, const string& str, size_type subpos, size_type sublen)
- string& replace(size_type pos, size_type n, const char* s)
- string& replace(size_type pos, size_type n, const char* s, size_type n2)
- string& replace(size_type pos, size_type n, size_type n2, char c)
- string& replace(iterator i1, iterator i2, const string& str)
- string& replace(iterator i1, iterator i2, const char* s)
- string& replace(iterator i1, iterator i2, const char* s, size_type n)
- string& replace(iterator i1, iterator i2, size_type n, char c)
- template<class InputIterator> string& replace(iterator i1, iterator i2, InputIterator first, InputIterator last)
- void swap(string& str)

[ String Operations ]
- const char* c_str() const
- const char* data() const
- allocator_type get_allocator() const
- size_type copy(char* s, size_type n, size_type pos = 0) const
- size_type find(const string& str, size_type pos = 0) const
- size_type find(const char* s, size_type pos = 0) const
- size_type find(const char* s, size_type pos, size_type n) const
- size_type find(char c, size_type pos = 0) const
- size_type rfind(const string& str, size_type pos = npos) const
- size_type rfind(const char* s, size_type pos = npos) const
- size_type rfind(const char* s, size_type pos, size_type n) const
- size_type rfind(char c, size_type pos = npos) const
- size_type find_first_of(const string& str, size_type pos = 0) const
- size_type find_first_of(const char* s, size_type pos = 0) const
- size_type find_first_of(const char* s, size_type pos, size_type n) const
- size_type find_first_of(char c, size_type pos = 0) const
- size_type find_last_of(const string& str, size_type pos = npos) const
- size_type find_last_of(const char* s, size_type pos = npos) const
- size_type find_last_of(const char* s, size_type pos, size_type n) const
- size_type find_last_of(char c, size_type pos = npos) const
- size_type find_first_not_of(const string& str, size_type pos = 0) const
- size_type find_first_not_of(const char* s, size_type pos = 0) const
- size_type find_first_not_of(const char* s, size_type pos, size_type n) const
- size_type find_first_not_of(char c, size_type pos = 0) const
- size_type find_last_not_of(const string& str, size_type pos = npos) const
- size_type find_last_not_of(const char* s, size_type pos = npos) const
- size_type find_last_not_of(const char* s, size_type pos, size_type n) const
- size_type find_last_not_of(char c, size_type pos = npos) const
- string substr(size_type pos = 0, size_type n = npos) const
- int compare(const string& str) const
- int compare(size_type pos, size_type n, const string& str) const
- int compare(size_type pos, size_type n, const string& str, size_type subpos, size_type sublen) const
- int compare(const char* s) const
- int compare(size_type pos, size_type n, const char* s) const
- int compare(size_type pos, size_type n, const char* s, size_type n2) const
