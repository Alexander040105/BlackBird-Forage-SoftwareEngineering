#  REPO_URL  https://github.com/Alexander040105/BlackBird-Forage-SoftwareEngineering
git switch -c update_logo
git add . 
git commit -m "changed the logo and the link into propeller logo" 
git push origin update_logo
gh pr create --title "Pull Request #1" --body "changed the logo and the link into propeller logo"
