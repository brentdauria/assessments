using System.Drawing;

namespace map_maker
{
    internal class Spritesheet
    {
        private string fileName;

        public Spritesheet(string fileName)
        {
            this.fileName = fileName;
        }

        public Image Image { get; internal set; }
    }
}