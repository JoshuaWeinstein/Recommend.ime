#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//Stores the information of each individual anime in the data set, such as its title and its genres.
class AnimeNode
{
	string iD;
	string titleJP;
	string titleEN;
	string image;
	string type;
	string source;
	string rating;
	string avgScore;
	string releaseDate;
	string studio;
	vector<string> genreList;

public:
	AnimeNode(string iD, string titleJP, string titleEN, string image, string type, string source, string rating, string avgScore, string releaseDate, string studio, vector<string> genreList)
	{
		this->iD = iD;
		this->titleJP = titleJP;
		this->titleEN = titleEN;
		this->image = image;
		this->type = type;
		this->source = source;
		this->rating = rating;
		this->avgScore = avgScore;
		this->releaseDate = releaseDate;
		this->studio = studio;
		this->genreList = genreList;
	}

	string getID()
	{
		return iD;
	}

	string getName(bool language)
	{
		if (language)
		{
			return titleJP;
		}
		else
		{
			return titleEN;
		}
	}

	string getType()
	{
		return type;
	}

	string getReleaseDate()
	{
		return releaseDate;
	}

	string getStudio()
	{
		return studio;
	}

	bool findGenre(string genre)
	{
		for (int i = 0; i < genreList.size(); i++)
		{
			if (genre == genreList[i])
			{
				return true;
			}
		}
		return false;
	}
};

//Stores each user's username and a map of their top scored shows for assistance in providing recommendations.
class User
{
	string username;
	unordered_map<string, string> topScores;

public:
	User(string username, unordered_map<string, string>* scores)
	{
		this->username = username;
		topScores = *scores;
	}

	unordered_map<string, string> getTopScores()
	{
		return topScores;
	}
};

class BinarySearchTree
{
	struct Node
	{
		AnimeNode* anime;
		double totalScore;
		Node* left;
		Node* right;
		Node(AnimeNode* anime, double totalScore)
		{
			this->anime = anime;
			this->totalScore = totalScore;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	Node* getRoot()
	{
		return root;
	}


	void insert(AnimeNode* toInsert, double toInsertScore)
	{
		if (this->root == nullptr)
		{
			this->root = new Node(toInsert, toInsertScore);
		}
		else
		{
			Node* root = this->root;
			bool inserted = false;
			while (!inserted)
			{
				if (root->totalScore > toInsertScore)
				{
					if (root->left != nullptr)
					{
						root = root->left;
					}
					else
					{
						root->left = new Node(toInsert, toInsertScore);
						inserted = true;
					}
				}
				else if (root->totalScore < toInsertScore)
				{
					if (root->right != nullptr)
					{
						root = root->right;
					}
					else
					{
						root->right = new Node(toInsert, toInsertScore);
						inserted = true;
					}
				}
				else
				{
					toInsertScore++;
				}
			}
		}
	}
	//Citation: Took inspiration from geeksforgeeks.org by using a stack to iterate through the Binary Search Tree.
	queue<AnimeNode*> generateTopTen()
	{
		queue<AnimeNode*> q;
		stack<Node*> s;
		Node* root = this->root;
		while (q.size() < 10)
		{
			if (root != nullptr)
			{
				s.push(root);
				root = root->right;
			}
			else
			{
				q.push(s.top()->anime);
				root = s.top()->left;
				s.pop();
			}
		}
		return q;
	}
};

//Generates a binary search tree using the recommendations from the function recommendationForInput.
BinarySearchTree* generateRecommendTree(unordered_map<string, double>* scoresMap, unordered_map<string, AnimeNode*>* animeList)
{
	BinarySearchTree* tree = new BinarySearchTree();

	auto it = scoresMap->begin();
	while (it != scoresMap->end())
	{
		if (animeList->count(it->first))
		{
			tree->insert(animeList->at(it->first), it->second);
		}
		it++;
	}
	return tree;
}

//Generates an ordered map using the recommendations from the function recommendationForInput.
map<double, AnimeNode*> generateRecommendMap(unordered_map<string, double>* scoresMap, unordered_map<string, AnimeNode*>* animeList)
{
	map<double, AnimeNode*> returnMap;
	auto it = scoresMap->begin();
	while (it != scoresMap->end())
	{
		while (returnMap.count(it->second))
		{
			it->second++;
		}
		if (animeList->count(it->first))
		{
			returnMap.emplace(it->second, animeList->at(it->first));
		}
		it++;
	}
	return returnMap;
}

//Helper function to adjustMap. Increases scores based on their compareRank, with lower values leading to larger multipliers.
double adjustScore(double score, int compareRank)
{
	if (compareRank == 1)
	{
		score *= 6;
	}
	else if (compareRank == 2)
	{
		score *= 4.5;
	}
	else if (compareRank == 3)
	{
		score *= 3;
	}
	else if (compareRank == 4)
	{
		score *= 2;
	}
	return score;
}

/* Helper function to adjustRecommendations. The attribute parameter dictates which attribute will be compared and the compareRank parameter
*  indicates how much a score will be multiplied by if a show matches a certain attribute. Example: if 2 and 4 are passed in for attribute
*  and compareRank respectively, the function will compare anime genres. If a match is found, the 4 indicates that it is the lowest priority,
*  so it will be incremented by the lowest amount.
*/
unordered_map<string, double> adjustMap(unordered_map<string, double>* scoresMap, unordered_map<string, AnimeNode*>* animeList, int attribute, string compare, int compareRank)
{
	if (compareRank != 0)
	{
		auto it = scoresMap->begin();
		while (it != scoresMap->end())
		{
			if (attribute == 1)
			{
				if (animeList->count(it->first))
				{
					if (animeList->at(it->first)->getType() == compare)
					{
						it->second = adjustScore(it->second, compareRank);
					}
				}
			}
			else if (attribute == 2)
			{
				if (animeList->count(it->first))
				{
					if (animeList->at(it->first)->findGenre(compare))
					{
						it->second = adjustScore(it->second, compareRank);
					}
				}
			}
			else if (attribute == 3)
			{
				if (animeList->count(it->first))
				{
					if (animeList->at(it->first)->getStudio().find(compare))
					{
						it->second = adjustScore(it->second, compareRank);
					}
				}
			}
			else if (attribute == 4)
			{
				if (animeList->count(it->first))
				{
					if (animeList->at(it->first)->getReleaseDate() == compare)
					{
						it->second = adjustScore(it->second, compareRank);
					}
				}
			}
			it++;
		}

	}
	return *scoresMap;
}

//Adjusts recommendations according to which attributes are valued most.
unordered_map<string, double> adjustRecommendations(unordered_map<string, double>* scoresMap, unordered_map<string, AnimeNode*>* animeList, string type, string genre, string studio, string releaseDate, int typeRank, int genreRank, int studioRank, int releaseDateRank)
{
	*scoresMap = adjustMap(scoresMap, animeList, 1, type, typeRank);
	*scoresMap = adjustMap(scoresMap, animeList, 2, genre, genreRank);
	*scoresMap = adjustMap(scoresMap, animeList, 3, studio, studioRank);
	*scoresMap = adjustMap(scoresMap, animeList, 4, releaseDate, releaseDateRank);
	return *scoresMap;
}

/* Takes in the title of the show as an input and converts it to its proper ID number found in the animeList map.
*  If the title is not present in the map, then the empty string is returned.
*/
string findID(string title, unordered_map<string, AnimeNode*>* animeList)
{
	string returnID = "";
	auto it = animeList->begin();
	while (it != animeList->end())
	{
		if (it->second->getName(true) == title || it->second->getName(false) == title)
		{
			returnID = it->first;
		}
		it++;
	}
	return returnID;
}

/* Generates a map to provide recommendations using user data. If a certain title is found among a user's highest score shows, then it is
*  added to the recommendation map barring that the user has not already watched it as indicated by the prevWatched vector. Once a title is added,
*  its score is placed as the value of the map. If the title already exists in the map, then its value is incremented by the score. Those titles
*  with the highest total scores will be used for recommendation.
*/
unordered_map<string, double> recommendationForInput(string title, unordered_map<string, AnimeNode*>* animeList, vector<User*>* userList, vector<string>* prevWatched)
{
	unordered_map<string, string> tempMap;
	unordered_map<string, double> totalScores;
	bool alreadyWatched = false;

	string inputID = findID(title, animeList);
	double adjustedScore = 0;

	if (inputID != "")
	{
		for (int i = 0; i < userList->size(); i++)
		{
			tempMap = userList->at(i)->getTopScores();
			if (tempMap.count(inputID))
			{
				auto it = tempMap.begin();
				while (it != tempMap.end())
				{
					for (int x = 0; x < prevWatched->size(); x++)
					{
						if (prevWatched->at(x) == it->first)
						{
							alreadyWatched = true;
						}
					}
					if (!alreadyWatched && inputID != it->first)
					{
						if (totalScores.count(it->first))
						{
							totalScores.at(it->first) += stoi(it->second);
						}
						else
						{
							totalScores.emplace(it->first, stoi(it->second));
						}
						adjustedScore = 0;
					}
					alreadyWatched = false;
					it++;
				}
			}
		}
		return totalScores;
	}
	else
	{
		cout << "Title not found in data. Please try again!" << endl;
		return totalScores;
	}
}

//Reads data from the file animelist.csv and converts the rows into objects named AnimeNodes.
void readAnimeFile(unordered_map<string, AnimeNode*>* animeList)
{

	ifstream animeListFile;
	string filler;

	string iD;
	string titleJP;
	string titleEN;
	string image;
	string type;
	string source;
	string rating;
	string avgScore;
	string releaseDate;
	string studio;
	string genres;

	int x = 0;
	string currGenre = "";
	vector<string> gList;
	AnimeNode* builderNode;

	animeListFile.open("files\\animeList.csv");
	getline(animeListFile, filler);
	getline(animeListFile, iD, ',');
	while (iD != "")
	{
		getline(animeListFile, titleJP, ',');
		getline(animeListFile, titleEN, ',');
		getline(animeListFile, image, ',');
		getline(animeListFile, type, ',');
		getline(animeListFile, source, ',');
		getline(animeListFile, rating, ',');
		getline(animeListFile, avgScore, ',');
		getline(animeListFile, releaseDate, ',');
		getline(animeListFile, studio, ',');
		getline(animeListFile, genres);

		while (x < genres.size())
		{
			if (genres.at(x) != '"' && genres.at(x) != ' ')
			{
				if (genres.at(x) != ',')
				{
					currGenre += genres.at(x);
				}
				else
				{
					gList.push_back(currGenre);
					currGenre = "";
					x++;
				}
			}
			x++;
		}
		gList.push_back(currGenre);

		// Filters out inappropriate titles
		if (rating.find("Rx"))
		{
			builderNode = new AnimeNode(iD, titleJP, titleEN, image, type, source, rating, avgScore, releaseDate, studio, gList);
			animeList->emplace(iD, builderNode);
		}
		currGenre = "";
		gList.clear();
		getline(animeListFile, iD, ',');
	}

	animeListFile.close();
}

//Reads data from the file useranimelist.csv. Reads the usernames, scores, and anime ID numbers of each row in order to create the User object.
void readUserFile(vector<User*>* userList)
{

	ifstream userListFile;
	string filler;

	string username;
	string prevUser;
	string iD;
	string score;
	unordered_map<string, string> scores;
	User* builderObj;

	userListFile.open("files\\useranimeList.csv");
	getline(userListFile, filler);
	getline(userListFile, username, ',');
	prevUser = username;

	while (username != "")
	{
		if (username == prevUser)
		{
			getline(userListFile, iD, ',');
			getline(userListFile, score);

			//Filters out scores below a 7 to help improve runtime when providing recommendations later
			if (stoi(score) >= 7)
			{
				scores.emplace(iD, score);
			}
		}
		else
		{
			builderObj = new User(prevUser, &scores);
			userList->push_back(builderObj);
			scores.clear();
			prevUser = username;
			getline(userListFile, iD, ',');
			getline(userListFile, score);
			if (stoi(score) >= 7)
			{
				scores.emplace(iD, score);
			}
		}
		getline(userListFile, username, ',');
	}
	builderObj = new User(prevUser, &scores);
	userList->push_back(builderObj);

	userListFile.close();
}

void readPrevWatchedFile(vector<string>* prevWatched)
{
	ifstream watchedFile;
	string filler;
	string insertID;

	watchedFile.open("files\\previouslywatched.csv");
	if (watchedFile.is_open())
	{
		getline(watchedFile, filler);
		getline(watchedFile, insertID);
		while (insertID != "")
		{
			prevWatched->push_back(insertID);
			getline(watchedFile, insertID);
		}
	}
	else
	{
		watchedFile.close();
		ofstream initializeFile;
		initializeFile.open("files\\previouslywatched.csv");

		initializeFile << "anime_id\n";

		cout << "Success!";

		initializeFile.close();
	}
	watchedFile.close();
}

void writePrevWatchedFile(vector<string>* prevWatched, string target, bool insertion)
{
	ofstream watchedFile;
	string filler;

	watchedFile.open("files\\previouslywatched.csv", ios::app);
	if (watchedFile.is_open())
	{
		if (insertion)
		{
			bool alreadyInserted = false;
			for (int i = 0; i < prevWatched->size(); i++)
			{
				if (prevWatched->at(i) == target)
				{
					alreadyInserted = true;
				}
			}
			if (!alreadyInserted)
			{
				prevWatched->push_back(target);
				watchedFile << target << "\n";
			}
			else
			{
				cout << "Already Inserted! Try Again!" << endl;
			}
			watchedFile.close();
		}
		else
		{
			watchedFile.close();
			ofstream newWatchedFile;
			newWatchedFile.open("files\\previouslywatched.csv", ios::trunc);
			newWatchedFile << "anime_id\n";

			bool removed = false;
			for (int i = 0; i < prevWatched->size(); i++)
			{
				if (prevWatched->at(i) == target)
				{
					prevWatched->at(i) = "-1";
					removed = true;
				}
				else
				{
					newWatchedFile << prevWatched->at(i) << "\n";
				}
			}
			if (removed)
			{
				cout << "Successfully Removed!" << endl;
			}
			else
			{
				cout << "Could not find the specified value. Please try again." << endl;
			}
			newWatchedFile.close();
		}
	}
}

int main()
{
	unordered_map<string, AnimeNode*> animeList;
	vector<User*> userList;
	vector<string> prevWatched;
	readPrevWatchedFile(&prevWatched);
	writePrevWatchedFile(&prevWatched, "69", true);
	writePrevWatchedFile(&prevWatched, "1", true);
	writePrevWatchedFile(&prevWatched, "2", true);
	writePrevWatchedFile(&prevWatched, "15", true);
	writePrevWatchedFile(&prevWatched, "1", false);
	readAnimeFile(&animeList);
	readUserFile(&userList);
	cout << animeList.size() << endl;
	cout << userList.size() << endl;

	unordered_map<string, double> recommendations = recommendationForInput("Tokyo Ghoul", &animeList, &userList, &prevWatched);
	cout << "Step 1 Complete" << endl;
	recommendations = adjustRecommendations(&recommendations, &animeList, "TV", "Comedy", "David Productions", "Winter 2019", 0, 1, 0, 0);
	cout << "Step 2 Complete" << endl;

	map<double, AnimeNode*> topTenMap = generateRecommendMap(&recommendations, &animeList);
	cout << "Map Generated" << endl;
	BinarySearchTree* tree = new BinarySearchTree();
	tree = generateRecommendTree(&recommendations, &animeList);
	cout << "Tree Generated" << endl;

	cout << "Map Recommendations:" << endl;
	auto it = topTenMap.end();
	it--;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". " << it->second->getName(true) << endl;
		it--;
	}

	cout << "Tree Recommendations:" << endl;
	queue<AnimeNode*> q = tree->generateTopTen();
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". " << q.front()->getName(true) << endl;
		q.pop();
	}

	return 0;
}