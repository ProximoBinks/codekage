export default function Header({ title }) {
  return (
    <header className="header">
      <h1 className="title">{title}</h1>
      <nav>
        <a href="/">Home</a>
        <a href="/board">Board</a>
        <a href="/timeline">Timeline</a>
      </nav>
      <style jsx>{`
        .header {
          display: flex;
          justify-content: space-between;
          align-items: center;
          padding: 1rem 2rem;
        }
        nav a {
          margin-left: 20px;
          text-decoration: none;
          color: #0070f3;
        }
        nav a:hover {
          text-decoration: underline;
        }
      `}</style>
    </header>
  );
}
