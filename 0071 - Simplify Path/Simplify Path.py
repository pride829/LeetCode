class Solution:
    def simplifyPath(self, path: str) -> str:
        # Scan the path from the start and record the previous scan start point.
        # If slash '/' is encountered, fetch the string from previous to position now.
        # This string could be folder indicator or folder name, parse it.
        
        name_stack = []
        prv = 0
        
        for i in range(len(path)):
            
            if path[i] == '/':
                name = ''.join(path[prv:i])
                prv = i + 1
                if name == "": # Double slash "//" will be treated like empty name ""
                    continue
                elif name == ".":
                    continue
                elif name == "..":
                    if name_stack:
                        name_stack.pop()
                else:
                    name_stack.append(name) # Store the names in a stack
        
        # End of path reached.
        # Repeat the process again but this time, name's end is the path's end. Because path may not end with slash '/'
        
        name = ''.join(path[prv:])
        
        if name == "":
            pass
        elif name == ".":
            pass
        elif name == "..":
            if name_stack:
                name_stack.pop()
        else:
            name_stack.append(name)
        
        if not name_stack:
            return "/"
        
        # Return the names in stack
        
        result = ""
        for name in name_stack:
            result += '/'
            result += name
        return result