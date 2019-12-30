#include <CLI/CLI.hpp>
#include <map>

enum class Level : int { High, Medium, Low };

int main(int argc, char **argv) {
    CLI::App app;

    Level level{Level::Low};
    // specify string->value mappings
    std::map<std::string, Level> map{{"high", Level::High}, {"medium", Level::Medium}, {"low", Level::Low}};
    // CheckedTransformer translates and checks whether the results are either in one of the strings or in one of the
    // translations already
    app.add_option("-l,--level", level, "Level settings")
        ->required()
        ->transform(CLI::CheckedTransformer(map, CLI::ignore_case));

    CLI11_PARSE(app, argc, argv);

    // CLI11's built in enum streaming can be used outside CLI11 like this:
    using namespace CLI::enums;
    std::cout << "Enum received: " << level << std::endl;

    return 0;
}
