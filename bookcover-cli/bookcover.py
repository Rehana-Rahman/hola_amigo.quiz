import requests
import random
from rich.console import Console
from rich.panel import Panel
from rich.text import Text

console = Console()

# Search popular subjects
subjects = [
    "fantasy", "romance", "science_fiction", "mystery", "thriller",
    "historical_fiction", "young_adult", "adventure", "horror", "classics"
]

def fetch_random_book():
    subject = random.choice(subjects)
    url = f"https://openlibrary.org/subjects/{subject}.json?limit=50"
    res = requests.get(url)
    books = res.json().get("works", [])

    if not books:
        console.print("❌ No books found. Try again.", style="bold red")
        return

    book = random.choice(books)
    title = book.get("title", "Untitled")
    authors = ", ".join([a['name'] for a in book.get("authors", [])])
    year = book.get("first_publish_year", "Unknown")
    cover_id = book.get("cover_id", None)

    cover_url = f"https://covers.openlibrary.org/b/id/{cover_id}-L.jpg" if cover_id else "No Cover Available"

    # Display as panel in terminal
    text = Text()
    text.append(f"\n📖 Title: {title}\n", style="bold cyan")
    text.append(f"✍️ Author(s): {authors or 'Unknown'}\n", style="bold green")
    text.append(f"📅 Year: {year}\n", style="bold yellow")
    text.append(f"🖼️ Cover URL: {cover_url}\n", style="bold magenta")

    console.print(Panel.fit(text, title=f"[bold white on blue] {subject.replace('_',' ').title()} ", padding=(1, 2)))

# Run it
while True:
    fetch_random_book()
    again = input("\n🔁 Generate another? (y/n): ").lower()
    if again != 'y':
        console.print("\n📚 See you soon, book wizard!", style="bold green")
        break
    
