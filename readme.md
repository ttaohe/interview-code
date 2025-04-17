## 20250417 wxg 技术架构团队
``` C++
Give an valid absolute path (Unix-style), simplified it.

- '.' represents the current directory, should be simplified.
- '..' represents the parent directory, should be simplified.
- '...' with more than 3 dots is treated as file name.
- Directories within the path must be separated by exactly one slash '/'.
- The path must start with a slash '/'.
- The path must not end with a slash '/' (except for the root path).

"/home/root/Documents/../Pictures/./" => "/home/root/Pictures"

"/home/root/Documents/../ttt/./Pictures/./" => "/home/root/Pictures"
"/../" => "/"

"/.../a/../b/c/../d/./" => "/.../b/d"

"/a/b/c/../../d/./" => "/a/d"

"/a/../../b/c/../../d/./" => "/d"

> string Simplify(string path);

```