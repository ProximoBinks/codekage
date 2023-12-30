import { useState } from 'react';

export default function ImageUpload({ onUpload }) {
  const [url, setUrl] = useState('');

  const handleUpload = () => {
    if (url) {
      onUpload(url);
      setUrl('');
    } else {
      alert("Please enter an image URL.");
    }
  };

  return (
    <div className="upload-container">
      <input
        type="text"
        placeholder="Enter image URL"
        value={url}
        onChange={(e) => setUrl(e.target.value)}
        className="url-input"
      />
      <button onClick={handleUpload} className="upload-button">Upload</button>
      <style jsx>{`
        .upload-container {
          margin: 20px;
          text-align: center;
        }
        .url-input {
          padding: 10px;
          margin-right: 10px;
          width: 300px;
          border-radius: 5px;
          border: 1px solid #ccc;
        }
        .upload-button {
          padding: 10px 20px;
          border-radius: 5px;
          background-color: #0070f3;
          color: white;
          border: none;
          cursor: pointer;
        }
        .upload-button:hover {
          background-color: #0056b3;
        }
      `}</style>
    </div>
  );
}
