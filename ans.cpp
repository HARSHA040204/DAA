//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "ans.h"

void Experiential::main(std::vector<std::wstring> &args)
{
try
{
std::shared_ptr<frequency_tree> file_one_words = std::make_shared<frequency_tree>();
std::shared_ptr<File> file_one = std::make_shared<File>(L"two.txt");
std::shared_ptr<Scanner> reader_one = std::make_shared<Scanner>(file_one);
while (reader_one->hasNextLine())
{
std::vector<std::wstring> words_one = reader_one->nextLine()->split(L" ");
for (auto i : words_one)
{
file_one_words->put(i);
}
}
std::wcout << L"File 1 :- ";
file_one_words->display();
reader_one->close();
std::shared_ptr<frequency_tree> file_two_words = std::make_shared<frequency_tree>();
std::shared_ptr<File> file_two = std::make_shared<File>(L"one.txt");
std::shared_ptr<Scanner> reader_two = std::make_shared<Scanner>(file_two);
while (reader_two->hasNextLine())
{
std::vector<std::wstring> words_two = reader_two->nextLine()->split(L" ");
for (auto j : words_two)
{
file_two_words->put(j);
}
}
std::wcout << L"File 2 :- ";
file_two_words->display();
reader_two->close();
std::vector<std::shared_ptr<avl_node>> common_words = file_one_words->common_words(file_two_words);
std::wcout << L"Common Words :- ";
common_words = top_3(common_words);
std::shared_ptr<subsequence> one_two = std::make_shared<subsequence>(common_words[0]->key,common_words[1]->key);
std::shared_ptr<subsequence> two_three = std::make_shared<subsequence>(one_two->LCS, common_words[2]->key);
std::wcout << L"\nSubsequence :- " << two_three->LCS << std::endl;
std::shared_ptr<FileWriter> writer = std::make_shared<FileWriter>(L"common_word.txt");
writer->write(two_three->LCS);
writer->close();
std::shared_ptr<Huffman> decoder = std::make_shared<Huffman>();
decoder->encoding(L"common_word.txt");
std::wcout << L"Key :- " << decoder->bits << std::endl;
}
catch (const std::runtime_error &e)
{
std::wcout << L"File Not Found" << std::endl;
}
}

std::vector<std::shared_ptr<avl_node>> Experiential::top_3(std::vector<std::shared_ptr<avl_node>> &i)
{
for (auto j : i)
{
std::wcout << L"[" << j->key << L" ," << j->value << L"] ";
}
std::vector<std::shared_ptr<avl_node>> one;
one.push_back(i[0]);
one.push_back(i[1]);
one.push_back(i[2]);
return one;
}

void frequency_tree::put(const std::wstring &key)
{
std::shared_ptr<avl_node> fresh = std::make_shared<avl_node>(key);
if (root == nullptr)
{
root = fresh;
}
else
{
if (!contains(key))
{
if (left_right == -1)
{
prev_track->left = fresh;
}
if (left_right == 1)
{
prev_track->right = fresh;
}
calculate_balance(this->root);
avl_balance(this->root,key);
}
else
{
track->value += 1;
}
}
}

bool frequency_tree::contains(const std::wstring &key)
{
track = root;
prev_track = root;
while (track != nullptr)
{
prev_track = track;
if (track->key->compareTo(key) > 0)
{
left_right = -1;
track = track->left;
}
else if (track->key->compareTo(key) < 0)
{
left_right = 1;
track = track->right;
}
else
{
break;
}
}
return track != nullptr;
}

std::vector<std::shared_ptr<avl_node>> frequency_tree::common_words(std::shared_ptr<frequency_tree> that)
{
std::vector<std::shared_ptr<avl_node>> common;
finds_common(that->root,common);
std::sort(common.begin(), common.end());
return common;
}

void frequency_tree::finds_common(std::shared_ptr<avl_node> root, std::vector<std::shared_ptr<avl_node>> &common)
{
if (root != nullptr)
{
finds_common(root->left,common);
if (this->contains(root->key))
{
std::shared_ptr<avl_node> one = std::make_shared<avl_node>(root->key);
one->value = root->value + track->value;
common.push_back(one);
}
finds_common(root->right,common);
}
}

int frequency_tree::height(std::shared_ptr<avl_node> root)
{
if (root == nullptr)
{
	return 0;
}
int left = height(root->left);
int right = height(root->right);
return right > left?(right + 1):(left + 1);
}

void frequency_tree::calculate_balance(std::shared_ptr<avl_node> root)
{
if (root != nullptr)
{
root->balance = height(root->left) - height(root->right);
calculate_balance(root->left);
calculate_balance(root->right);
}
}

void frequency_tree::display()
{
std::shared_ptr<avl_node> trace = root;
show_ascending(trace);
std::wcout << std::endl;
}


//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
