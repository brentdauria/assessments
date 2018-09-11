using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace map_maker
{
    public partial class Form1 : Form
    {
        Spritesheet spritesheet = null;
        Bitmap drawArea;

        int gridwidth = 16;
        int gridhieght = 20;
        int spacing = 0;



        public Form1()
        {
            InitializeComponent();
            drawArea = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        private void Button3_Click(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();

            if (dlg.ShowDialog() == DialogResult.OK)
            {
                if (dlg.CheckFileExists == true)
                {
                    spritesheet = new Spritesheet(dlg.FileName);
                    Drawgrid();
                }
            }

        }
        private void Drawgrid()
        {
            pictureBox1.DrawToBitmap(drawArea, pictureBox1.Bounds);
            Graphics g;
            g = Graphics.FromImage(drawArea);
            g.Clear(Color.White);

            if(spritesheet !=null)
            {
                g.DrawImage(spritesheet.Image, 0, 0);
            }
            Pen pen = new Pen(Brushes.Black);
            int hieght = pictureBox1.Height;
            int width = pictureBox1.Width;
            for (int y = 0; y < Height; y += gridhieght + spacing)
            {
                g.DrawLine(pen, 0, y, width, y);
            }

            for (int x = 0; x < width; x += gridwidth + spacing)
            {
                g.DrawLine(pen, x, 0, x, Height);
            }
            g.Dispose();
            
            pictureBox1.Image = drawArea;
        }
      // private void TextBoxHeight_TextChanged(object sender, EventArgs e)
      // {
      //     if (int.TryParse(TextBoxHeight_TextChanged.Text, out gridhieght) == true)
      //     {
      //         Drawgrid();
      //     }
      //     TextBoxHeight_TextChanged = gridhieght.ToString();
      // }


        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {


        }

        private void Form1_DragDrop(object sender, DragEventArgs e)
        {

        }


      

    }
}
