//
// Created by giulia on 03/10/20.
//

#include "/home/giulia/CLionProjects/Programmazione/test/lib/googletest/include/gtest/gtest.h"
#include "../File.h"
#include "../LoadResources.h"
#include "../ConcreteObserver.h"

TEST(TestFile, testNonExistentResource) {
    ASSERT_THROW(File file("../resources/None.txt"), runtime_error);
}

TEST(TestFile, testExistentResource) {
    ASSERT_NO_THROW(File file("../resources/File.txt"));
}

TEST(TestFile, testSizeForExistentFile) {
    File file("../resources/File.txt");
    ASSERT_FALSE(file.getFileSize()==0);
}

TEST(TestLoadResources, testNoFileNamesProvided) {
    std::vector<string> vector;
    LoadResources loader;
    loader.load(vector);
    ASSERT_EQ(loader.getNumberResources(),0);
}

TEST(TestLoadResources, testFileNamesProvided) {
    std::vector<string> vector;
    vector.emplace_back("anything");
    LoadResources loader;
    loader.load(vector);
    ASSERT_FALSE(loader.getNumberResources()==0);
}


TEST(TestObserver, testFileName) {
    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<string> vector;
    vector.emplace_back("filename.txt");
    loader.load(vector);

    ASSERT_EQ(observer.res->getFileName(), "filename.txt");

}

TEST(TestObserver, testFileSize) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<string> vector;
    vector.emplace_back("../resources/File.txt");
    loader.load(vector);

    ASSERT_EQ(observer.res->getFileSize(), 7);

}

TEST(TestObserver, testLoaded) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<string> vector;
    vector.emplace_back("../resources/File.txt");
    loader.load(vector);

    ASSERT_EQ(observer.res->loadedFile(), true);

}