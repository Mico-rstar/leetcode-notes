# cpp/vector



### Element access: at vs []
```cpp
arr[1] // 无边界检查，越界发生运行时错误
arr.at(1) // 越界会抛出异常，需要处理异常
```

---


### Iterator
#### begin & cbegin
- begin: 返回可修改迭代器
- cbegin: 只读迭代器

#### end & cend、
- 充当哨兵角色，不能解引用
- 集合为空时，begin() == end()

#### rbegin & crbegin & rend & crend
- 相反迭代器

---

### Capacity
- empty: 判断是否为空集合
- size: 集合元素个数
- reserve: 提前告知需要分配的空间
- capacity: 已经分配的空间大小

### Modifiers
```cpp
vector<int> vec = {1, 2, 3};

// 清除操作
vec.clear();

// 插入操作(insert after pos) 
auto pos = vec.begin();
vec.insert(pos, 200);

// 范围插入(insert after pos)
auto pos = std::next(vec.begin(), 2);
const auto rg = std::list{-1, -2, -4};
vec.insert_range(pos, rg);
vec.append_range(rg); // 插入末尾

// 集合内构造
vector<pair<int, int>> vp;
auto pos = vp.begin();
vp.emplace(pos, 1, 2); // 直接传入参数列表，在集合内原地构造std::pair<int, int>

vp.emplace_back(3, 2); // 在末尾构造

// 删除元素
vec.erase(pos); // 删除指定元素
vec.erase(vec.begin(), vec.end()); // 范围删除，左闭右开区间


```
 
