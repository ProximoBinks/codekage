import styles from './Footer.module.css'

export default function Footer() {
  return (
    <footer className={styles.footer}>
      <div>
        <p>Follow us on social media!</p>
        {/* Icons or links to social media profiles */}
      </div>
      <img src="/logo-netlify.svg" alt="Netlify Logo" className={styles.logo} />
      <div>
        <p>Contact us: contact@example.com</p>
        {/* Other contact information or quick links */}
      </div>
    </footer>
  )
}
