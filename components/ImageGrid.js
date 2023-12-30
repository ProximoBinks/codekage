export default function ImageGrid({ images }) {
    return (
      <div className="image-grid">
        {images.map((img, index) => (
          <div key={index} className="image-item">
            <img src={img} alt={`Image ${index}`} />
          </div>
        ))}
        <style jsx>{`
          .image-grid {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
            gap: 15px;
            padding: 20px;
          }
          .image-item img {
            width: 100%;
            height: auto;
            border-radius: 8px;
            object-fit: cover;
          }
        `}</style>
      </div>
    );
  }
  