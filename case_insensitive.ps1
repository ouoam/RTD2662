echo "Disabling case sensitivity for this directory and all subdirectories..."
fsutil.exe file setCaseSensitiveInfo . disable
(Get-ChildItem -Recurse -Directory).FullName | ForEach-Object {fsutil.exe file setCaseSensitiveInfo $_ disable}
