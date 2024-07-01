from os import path
import os

script_path = path.join(os.path.dirname(os.path.realpath("__file__")), "web")


def read_file(file_path):
    with open(file_path, "r") as file:
        return file.read()


def generate_header(file_path, header_path):
    file_contents = read_file(file_path).split("\n")

    for i, file_content in enumerate(file_contents):
        if file_content != "":
            pre_str = '\t\t"'
            post_str = '\\n"'
            content = file_content.replace('"', '\\"')

            file_contents[i] = f"{pre_str}{content}{post_str}"
        else:
            file_contents.pop(i)

    content = "\n".join(file_contents)

    with open(header_path, "w") as header_file:
        header_file.write("#ifndef WEB_CONTENT_H\n")
        header_file.write("#define WEB_CONTENT_H\n\n")
        header_file.write("#include <WString.h>\n")
        header_file.write("const String RGB_WEB_CONTENT =\n")
        header_file.write(f"{content};\n\n")
        header_file.write("#endif  // WEB_CONTENT_H\n")


generate_header(
    path.abspath(path.join(script_path, "index.html")),
    path.abspath(
        path.join(script_path, "..", "lib", "esp", "src", "esp", "server", "web.h")
    ),
)
