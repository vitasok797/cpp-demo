#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include <algorithm>

TEST(NlohmannJsonTest, ParseFromString)
{
    auto json_str = R"({"pi": 3.14, "happy": true})";
    auto json = nlohmann::json::parse(json_str);

    EXPECT_EQ(json["pi"], 3.14);
    EXPECT_EQ(json["happy"], true);
}

struct Person
{
    std::string first_name;
    std::string last_name;
    int age;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE(Person, first_name, last_name, age);

TEST(NlohmannJsonTest, SerializeStruct)
{
    auto p = Person{"John", "Smith", 20};
    auto json = nlohmann::ordered_json(p);

    EXPECT_EQ(json.dump(), R"({"first_name":"John","last_name":"Smith","age":20})");
}

TEST(NlohmannJsonTest, SerializePrettyCompact)
{
    auto json_str = R"({"first_name": "John", "last_name": "Smith"})";
    auto json = nlohmann::json::parse(json_str);

    auto json_pretty_compact = json.dump(0);
    std::ranges::replace(json_pretty_compact, '\n', ' ');

    EXPECT_EQ(json_pretty_compact, R"({ "first_name": "John", "last_name": "Smith" })");
}
