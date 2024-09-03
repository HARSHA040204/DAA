

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "tangible_rectangular_vectors.h"
#include "tangible_string_helper.h"

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
class avl_node;
class Node;
class node_Priority_Queue;

class Experiential : public std::enable_shared_from_this<Experiential>
{
 public:
 static void main(std::vector<std::wstring> &args);
 static std::vector<std::shared_ptr<avl_node>> top_3(std::vector<std::shared_ptr<avl_node>> &i);
};
class frequency_tree : public std::enable_shared_from_this<frequency_tree>
{
 public:
 std::shared_ptr<avl_node> root = nullptr;
 int left_right = 0;
 private:
 std::shared_ptr<avl_node> track;
 std::shared_ptr<avl_node> prev_track;
 public:
 virtual void put(const std::wstring &key);
 private:
 bool contains(const std::wstring &key);
 public:
 virtual std::vector<std::shared_ptr<avl_node>> common_words(std::shared_ptr<frequency_tree> that);
 private:
 void finds_common(std::shared_ptr<avl_node> root, std::vector<std::shared_ptr<avl_node>> &common);
 int height(std::shared_ptr<avl_node> root);
 public:
 virtual void calculate_balance(std::shared_ptr<avl_node> root);
 virtual void display();
 private:
 void show_ascending(std::shared_ptr<avl_node> root);
 public:
 virtual void avl_balance(std::shared_ptr<avl_node> root, const std::wstring &key);
 private:
 void left_rotate(std::shared_ptr<avl_node> prev_unbalance, std::shared_ptr<avl_node> recent_unbalance, int ind);
 void right_rotate(std::shared_ptr<avl_node> prev_unbalance, std::shared_ptr<avl_node> recent_unbalance, int ind);
 void left_right_rotate(std::shared_ptr<avl_node> prev_unbalance, std::shared_ptr<avl_node> recent_unbalance, int ind);
 void right_left_rotate(std::shared_ptr<avl_node> prev_unbalance, std::shared_ptr<avl_node> recent_unbalance, int ind);
};
class avl_node : public std::enable_shared_from_this<avl_node>, public Comparable<std::shared_ptr<avl_node>>
{ //avl_node implements interface Comparable
public:
std::shared_ptr<to> make;
 int value = 0;
 int balance = 0;
 avl_node(const std::wstring &key);
 std::shared_ptr<avl_node> left = nullptr;
 std::shared_ptr<avl_node> right = nullptr;
 virtual int compareTo(std::shared_ptr<avl_node> that);
};
class subsequence : public std::enable_shared_from_this<subsequence>
{
 public:
 int m = 0, n = 0;
 std::vector<std::vector<int>> count;
 std::vector<std::vector<std::wstring>> pointers;
 std::wstring one, two, LCS = L"";
 int length_of_subsequence = 0;
 subsequence(const std::wstring &one, const std::wstring &two);
 virtual void find_length();
 virtual void find_LCS();
};
class Huffman : public std::enable_shared_from_this<Huffman>
{
 public:
 std::shared_ptr<Node> track; //To refer a node when calculating frequency
 std::shared_ptr<Node> tree_head; // Tree head of huffman
 std::vector<std::shared_ptr<Node>> character_code = std::vector<std::shared_ptr<Node>>(); //After finding code for each
//character,this list can be used to match character with it's code
 std::wstring bits = L"";
 virtual void encoding(const std::wstring &name);
 std::wstring s = L"";
 virtual void fill_character_code();
 virtual void find_code(std::shared_ptr<Node> head);
 virtual void form_a_tree(std::shared_ptr<node_Priority_Queue> list);
 virtual bool contains(std::vector<std::shared_ptr<Node>> &f, const std::wstring &s);
};
class node_Priority_Queue : public std::enable_shared_from_this<node_Priority_Queue>
{
 public:
 std::vector<std::shared_ptr<Node>> list_of_characters = std::vector<std::shared_ptr<Node>>();
 virtual void add(std::shared_ptr<Node> item);
 virtual void add_maintain_heap(std::shared_ptr<Node> item);
 virtual void heapify();
 private:
 void sink(int index);
 void swim();
 public:
 virtual std::shared_ptr<Node> del_min();
};
class Node : public std::enable_shared_from_this<Node>
{
 public:
 std::shared_ptr<Node> left;
 std::shared_ptr<Node> right;
 std::wstring key;
 int frequency = 0;
 std::wstring code;
 Node(const std::wstring &key, int frequency);
 Node(const std::wstring &key, const std::wstring &code);
};
